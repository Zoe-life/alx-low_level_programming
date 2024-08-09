#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow, *fast;
    size_t count = 0;

    if (head == NULL)
        return 0;

    slow = head;
    fast = head->next;

    while (fast && fast->next)
    {
        if (slow == fast)
        {
            while (slow != fast->next)
            {
                printf("[%p] %d\n", (void *)slow, slow->n);
                slow = slow->next;
                count++;
            }
            printf("[%p] %d\n", (void *)slow, slow->n);
            printf("-> [%p] %d\n", (void *)fast, fast->n);
            exit(98);
        }
        slow = slow->next;
        fast = fast->next->next;
        count++;
    }

    while (slow)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        slow = slow->next;
        count++;
    }

    return count;
}
