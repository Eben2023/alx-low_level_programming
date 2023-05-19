#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * in a doubly linked list.
 * @h: Double pointer to the head of the doubly linked list.
 * @idx: Index where the new node should be added, starting from 0.
 * @n: Value to be assigned to the new node.
 *
 * Return: The address of the new node on success, or NULL if it fails
 * or is not possible to add the new node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node, *c_ptr = *h;
unsigned int i;

if (idx == 0)
return (add_dnodeint(h, n));
for (i = 0; i < idx - 1 && c_ptr != NULL; i++)
c_ptr = c_ptr->next;
if (c_ptr == NULL)
return (NULL);
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->prev = c_ptr;
new_node->next = c_ptr->next;

if (c_ptr->next != NULL)
c_ptr->next->prev = new_node;

c_ptr->next = new_node;

return (new_node);
}
