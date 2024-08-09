#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - Prints all elements of a listint_t list.
 * @h: The head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
    size_t nodes = 0;

    while (h != NULL)
    {
        _putchar('[');
        _putchar(h->n % 10 + '0');  // Print individual digits for flexibility
        if (h->n < 0)
        {
            _putchar('-');
        }
        _putchar(']');
        _putchar(' ');

        nodes++;
        h = h->next;
    }

    _putchar('\n');
    return nodes;
}