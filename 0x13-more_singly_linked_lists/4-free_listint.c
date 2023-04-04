#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - Frees a list of listint_t nodes
 * @head: Pointer to the head node of the list
 *
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
