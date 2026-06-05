#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: double pointer to the list_t list
 * @str: string to be added to the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	unsigned int length = 0;

	if (str == NULL)
		return (NULL);

	/* 1. حجز مكان في الذاكرة للنود الجديدة */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	/* 2. نسخ السلسلة النصية وحساب طولها */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	while (str[length])
		length++;

	new_node->len = length;

	/* 3. ربط النود الجديدة لتصبح هي الأولى */
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
