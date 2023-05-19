#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list.
 * @head: Double pointer to the head of the doubly linked list.
 * @n: Value to be assigned to the new node.
 *
 * Return: (Address of the new element) on success, or (NULL) if it fails.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *newNode;
dlistint_t *temp;

newNode = malloc(sizeof(dlistint_t));
if (newNode == NULL)
return (NULL);

newNode->n = n;
newNode->next = NULL;

if (*head == NULL)
{
newNode->prev = NULL;
*head = newNode;
}
else
{
temp = *head;
while (temp->next != NULL)
temp = temp->next;

temp->next = newNode;
newNode->prev = temp;
}

return (newNode);
}
