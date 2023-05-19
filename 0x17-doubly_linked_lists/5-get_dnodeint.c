#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a doubly linked list.
 * @head: Pointer to the head of the doubly linked list.
 * @index: Index of the node to retrieve, starting from 0.
 *
 * Return: Pointer to the nth node, or NULL if the node does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
unsigned int num = 0;
dlistint_t *c_ptr = head;

while (c_ptr != NULL)
{
if (num == index)
return (c_ptr);

c_ptr = c_ptr->next;
num++;
}

return (NULL);
}
