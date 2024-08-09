#include "lists.h"

/**
 * get_dnodeint_at_index - Gets the nth node of a dlistint_t linked list.
 * @head: The head of the list.
 * @index: The index of the node, starting from 0.
 *
 * Return: The nth node, or NULL if it does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int i;

    if (head == NULL)
        return (NULL);

    for (i = 0; i < index && head != NULL; i++)
        head = head->next;

    return (head);
}