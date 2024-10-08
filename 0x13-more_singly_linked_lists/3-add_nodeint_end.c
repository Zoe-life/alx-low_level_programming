#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: A double pointer to the head of the list.
 * @n: The integer data for the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new, *temp;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return NULL;

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }

    return new;
}