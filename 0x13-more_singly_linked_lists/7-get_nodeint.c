#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: A pointer to the head of the list.
 * @index: The index of the node, starting at 0.
 *
 * Return: The nth node, or NULL if it does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i;

    if (head == NULL)
        return NULL;

    for (i = 0; i < index && head != NULL; i++)
        head = head->next;

    return (i == index) ? head : NULL;
}