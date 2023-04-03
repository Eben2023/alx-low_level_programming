#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 *
 * @head: pointer to a pointer to the head of the list
 * @n: value to add to the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node, *current_node;

/* Allocate memory for the new node */
new_node = malloc(sizeof(listint_t));
if (!new_node)
return (NULL);

/* Initialize new node */
new_node->n = n;
new_node->next = NULL;

/* If head is null, new node becomes head */
if (!*head)
{
*head = new_node;
return (new_node);
}

/* Find the last node */
current_node = *head;
while (current_node->next)
current_node = current_node->next;

/* Add new node at the end */
current_node->next = new_node;

return (new_node);
}

