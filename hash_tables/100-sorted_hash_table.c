#include "hash_tables.h"

void insert_sorted_list(shash_table_t *ht, shash_node_t *new_node);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the created table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * insert_sorted_list - Inserts a node into the sorted doubly linked list.
 * @ht: A pointer to the sorted hash table.
 * @new_node: The node to insert.
 */
void insert_sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *curr;

	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
		new_node->sprev = NULL;
		new_node->snext = NULL;
		return;
	}
	if (strcmp(new_node->key, ht->shead->key) < 0)
	{
		new_node->snext = ht->shead;
		new_node->sprev = NULL;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
		return;
	}
	curr = ht->shead;
	while (curr->snext != NULL && strcmp(new_node->key, curr->snext->key) > 0)
		curr = curr->snext;

	new_node->snext = curr->snext;
	new_node->sprev = curr;
	if (curr->snext == NULL)
		ht->stail = new_node;
	else
		curr->snext->sprev = new_node;
	curr->snext = new_node;
}

/**
 * shash_table_set - Adds or updates an element in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add (cannot be empty).
 * @value: The value associated with key.
 *
 * Return: 1 if succeeded, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *temp;
	char *value_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = value_copy;
			return (1);
		}
		temp = temp->next;
	}
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(value_copy);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		free(value_copy);
		return (0);
	}
	new_node->value = value_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	insert_sorted_list(ht, new_node);
	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to look for.
 *
 * Return: The value, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->array[index];
	while (node && strcmp(node->key, key) != 0)
		node = node->next;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Prints a sorted hash table using its sorted list.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->shead;
	while (node != NULL)
	{
		if (comma_flag == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		comma_flag = 1;
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->stail;
	while (node != NULL)
	{
		if (comma_flag == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		comma_flag = 1;
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node != NULL)
	{
		temp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = temp;
	}
	free(ht->array);
	free(ht);
}
