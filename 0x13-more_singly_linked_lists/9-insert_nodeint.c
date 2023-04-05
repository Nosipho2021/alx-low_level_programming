#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @idx: Index of list where the new node should be added. Index starts at 0
 * @head: Pointer to pointerto the head node of the list
 * @n: Value to be assigned to the new node
 *
 * Return: Pointer to new node, or NULL if the new node could not be added
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *prev_node, *current_node;
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	prev_node->next = NULL;
	current_node = *head;

	while (current_node != NULL && i < idx)
	{
		prev_node = current_node;
		current_node = current_node->next;
		i++;
	}

	if (i < idx)
	{
		free(new_node);
		return (NULL);
	}

	prev_node->next = new_node;
	new_node->next = current_node;

	return (new_node);
}

