#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t linked list
 * @h: pointer to the head of the linked list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0; listint_t *current, *next;

	if ( NULL || *h == NULL)
	return (0);

	current = *h;
	*h = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		count++;
		current = next;
	}

	return (count);
}

