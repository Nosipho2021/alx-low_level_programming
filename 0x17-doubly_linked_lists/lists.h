#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

/* Struct for doubly linked list node */
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

/* Struct for dlistint_t node (assuming it's the same as Node) */
typedef struct dlistint_t
{
    int n;
    struct dlistint_t *prev;
    struct dlistint_t *next;
} dlistint_t;

/* Function prototypes */
size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(dlistint_t *head);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
int sum_dlistint(dlistint_t *head);
/* Add other function prototypes here if needed */

#endif /* LISTS_H */

