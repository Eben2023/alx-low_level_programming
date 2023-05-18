#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a doubly linked list.
 * @h: Pointer to the head of the doubly linked list.
 *
 * Return: The number of elements (nodes) in the doubly linked list.
 */
size_t dlistint_len(const dlistint_t *h)
{
size_t number = 0;

while (h != NULL)
{
number++;
h = h->next;
}

return number;
}
