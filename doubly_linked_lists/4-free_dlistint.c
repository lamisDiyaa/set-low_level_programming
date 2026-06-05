#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the doubly linked list
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head->next; /* احتفظ بمكان النود القادمة قبل حذف الحالية */
		free(head);        /* حرر النود الحالية من الذاكرة */
		head = temp;       /* انقل الـ head للنود القادمة */
	}
}
