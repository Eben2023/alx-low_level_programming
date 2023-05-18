#include "lists.h"
/**
 * add_dnodeint - Adds a new node at the beginning of a doubly linked list.
 * @head: Double pointer to the head of the doubly linked list.
 * @n: Value to be assigned to the new node.
 *
 * Return: (Address of the new element) on success, or (NULL) if it fails.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
dlistint_t *newNode;

newNode = malloc(sizeof(dlistint_t));
if (newNode == NULL)
return (NULL);

newNode->n = n;
newNode->prev = NULL;
newNode->next = *head;

if (*head != NULL)
(*head)->prev = newNode;

*head = newNode;

return (newNode);
}
