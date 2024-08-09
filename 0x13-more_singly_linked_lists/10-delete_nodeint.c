#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index.
 * @head: A double pointer to the head of the list.
 * @index: The index of the node to delete.
 *
 * Return: 1 if successful, -1 if it fails.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *temp, *prev;
    unsigned int i;

    if (*head == NULL)
        return -1;

    if (index == 0)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return 1;
    }

    temp = *head;
    for (i = 0; i < index - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return -1;

    prev = temp;
    temp = temp->next;
    prev->next = temp->next;
    free(temp);

    return 1;
}