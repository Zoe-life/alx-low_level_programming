#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index index of a dlistint_t linked list.
 * @head: Double pointer to the head of the list.
 * @index: Index of the node to be deleted. Index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp = *head;
    unsigned int i;

    if (*head == NULL)
        return (-1);

    if (index == 0) {
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return (1);
    }

    for (i = 0; i < index && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return (-1);

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    return (1);
}