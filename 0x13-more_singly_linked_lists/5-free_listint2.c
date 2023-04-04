#include "lists.h"

/**
 * free_listint2 -frees a listint_t list
 * @head: pointer to pointer to head node of list
 */
void free_listint2(listint_t **head)
{
	listint_t *current, *tmp;

	if (head == NULL)
		return;

	current = *head;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*head = NULL;
}
