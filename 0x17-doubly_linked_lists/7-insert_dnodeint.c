#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position in a dlistint_t list.
 * @h: Double pointer to the head of the list.
 * @idx: Index of the list where the new node should be added.
 * @n: Integer to store in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new, *temp;
    unsigned int i;

    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;

    if (idx == 0)
        return (add_dnodeint(h, n));

    temp = *h;
    for (i = 0; i < idx - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return (NULL);

    new->next = temp->next;
    new->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = new;
    temp->next = new;

    return (new);
}