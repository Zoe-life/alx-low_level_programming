#include "lists.h"

/**
 * reverse_listint - Reverses a linked list.
 * @head: A double pointer to the head of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev, *next;

    if (*head == NULL || (*head)->next == NULL)
        return *head;

    prev = NULL;
    next = NULL;

    while (*head != NULL)
    {
        next = (*head)->next;
        (*head)->next = prev;
        prev = *head;
        *head = next;
    }

    *head = prev;
    return *head;
}