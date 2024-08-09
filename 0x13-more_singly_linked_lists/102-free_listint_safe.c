#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @head: A double pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *tmp, *next;
    size_t count = 0;

    if (*h == NULL)
        return 0;

    tmp = *h;
    next = (*h)->next;

    while (tmp)
    {
        if (tmp == next)
        {
            free(tmp);
            *h = NULL;
            return count;
        }
        free(tmp);
        tmp = next;
        next = next ? next->next : NULL;
        count++;
    }

    *h = NULL;
    return count;
}