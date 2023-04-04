#include <stdlib.h>
#include "list.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list
 * @head: Pointer to a pointer to the head node of the list
 *
 * Return: The data of the deleted head node,  or 0 if the list is empty
 * Description: A function pop_listint deletes the head node
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int data;

	if (*head == NULL)
		return (0);

	temp = *head;
	data = temp->n;
	*head = (*head)->next;
	free(temp);

	return (data);
}
