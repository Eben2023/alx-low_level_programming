#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list.
 * @head: Pointer to pointer to the first node of the list.
 *
 * Description: Frees a listint_t list and sets the head to NULL.
 */
void free_listint2(listint_t **head)
{
listint_t *current;

if (head == NULL)
return;

while (*head != NULL)
{
current = *head;
*head = (*head)->next;
free(current);
}

*head = NULL;
}
