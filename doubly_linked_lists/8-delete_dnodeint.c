#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node that should be deleted, starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int count = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	/* 1. لو المطلوب حذف أول نود (اندكس 0) */
	if (index == 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	/* 2. التحرك للوصول للنود المطلوبة عند الاندكس بالظبط */
	while (temp != NULL && count < index)
	{
		temp = temp->next;
		count++;
	}

	/* 3. لو الاندكس المطلوب بره حدود اللستة */
	if (temp == NULL)
		return (-1);

	/* 4. ربط النود السابقة بالنود التالية لتخطي النود الحالية */
	if (temp->prev != NULL)
		temp->prev->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	free(temp);
	return (1);
}
