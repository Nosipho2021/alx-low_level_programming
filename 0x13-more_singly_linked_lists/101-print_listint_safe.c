#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head node of the list
 *
 * Return:the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t count = 0;

	while (slow && fast && fast->next)
	{
		printf("[%p] %d\n", (void *) slow, slow->n);
		count++;
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			printf("[%p] %d\n", (void *) head, head->n);
			count++;
			head = head->next;
			while (head != slow)
			{
				printf("[%p] %d\n", (void *) head, head->n);
				count++
				head = head->next;
			}

			exit(98);

		}

		while (head)
		{
			printf("[%p] %d\n", (void *) head, head->n);
			count++;
			head = head->next;
		}

		return (count);

