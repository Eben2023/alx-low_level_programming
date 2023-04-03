#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of a listint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node that should be deleted, starting at 0
 *
 * Return: 1 if the node is successfully deleted, -1 otherwise
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
if (*head == NULL)
{
return (-1); /* list is empty */
}

if (index == 0)
{
listint_t *temp = *head;
*head = (*head)->next;
free(temp);
return (1);
}

listint_t *prev = NULL;
listint_t *current = *head;
unsigned int i = 0;

while (i < index && current != NULL)
{
prev = current;
current = current->next;
i++;
}

if (current == NULL)
{
return (-1); /* index is out of range */
}

prev->next = current->next;
free(current);

return (1);
}
