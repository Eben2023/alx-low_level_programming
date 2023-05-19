#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data in a doubly linked list.
 * @head: Pointer to the head of the doubly linked list.
 *
 * Return: The sum of all the data in the doubly linked list, or 0 if the
 * list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
int sum = 0;
dlistint_t *c_ptr = head;

while (c_ptr != NULL)
{
sum += c_ptr->n;
c_ptr = c_ptr->next;
}

return (sum);
}
