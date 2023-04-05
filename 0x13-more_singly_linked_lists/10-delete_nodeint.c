#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * delete_nodeint_at_index - deletes the node at specified index
 * @head: Pointer to the head of the linked list
 * @index: Index of the node to be deleted, starting from 0
 *
 * Return: 1 on success, -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		listint_t *temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	listint_t *prev = *head;
	listint_t *current = (*head)->next;
	unsigned int i = (1);

	while (current != NULL && i < index)
	{
		prev = current->next;
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	prev->next = current->next;
	free(current);
	return (1);
}
