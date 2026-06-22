#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: If something went wrong - NULL.
 * Otherwise - a pointer to the newly created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	/* 1. حجز مكان لهيكل الجدول في الذاكرة */
	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	/* 2. حجز مكان للمصفوفة التي ستحتوي على العناصر (المؤشرات) */
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->size = size;

	/* 3. تهيئة كل خانة في المصفوفة لتشير إلى NULL */
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}
