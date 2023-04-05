#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t linked
 * @h: pointer to the head node of the linked list
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow = *h, *fast = *fast = *h;
	size_t count = 0;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			count++;
			while (*h != slow)
			{
				listint_t *temp = *h;
				*h = (*h)->next;
				free(temp);
				count++;
			}
			*h = (*h)->next;
			free(temp);
			count++;
		}
	}
	while (*h)
	{
		listint_t *temp = *h;
		*h = (*h)->next;
		free(temp);
		count++;
	}

	return (count);

}
