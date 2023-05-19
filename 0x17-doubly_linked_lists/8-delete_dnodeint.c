#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given position in a
 * doubly linked list.
 * @head: Double pointer to the head of the doubly linked list.
 * @index: Index of the node to be deleted, starting from 0.
 *
 * Return: 1 if the deletion succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *c_ptr = *head;
unsigned int x;

if (c_ptr == NULL)
return (-1);
if (index == 0)
{
*head = c_ptr->next;
if (c_ptr->next != NULL)
c_ptr->next->prev = NULL;
free(c_ptr);
return (1);
}
for (x = 0; x < index && c_ptr != NULL; x++)
c_ptr = c_ptr->next;
if (c_ptr == NULL)
return (-1);
if (c_ptr->prev != NULL)
c_ptr->prev->next = c_ptr->next;
if (c_ptr->next != NULL)
c_ptr->next->prev = c_ptr->prev;

free(c_ptr);
return (1);
}
