#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - Reverses a linked list
 * @head: Double pointer to head of list
 *
 * Return: Pointer to new head of list
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *prev = NULL;
listint_t *current = *head;
listint_t *next = NULL;

while (current != NULL)
{
next = current->next;
current->next = prev;
prev = current;
current = next;
}
*head = prev;
return (*head);
}
