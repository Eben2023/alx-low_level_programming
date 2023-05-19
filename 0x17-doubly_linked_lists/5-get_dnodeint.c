#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list.
 * @head: Pointer to the head of the doubly linked list.
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
dlistint_t *c_ptr;

while (head != NULL)
{
c_ptr = head;
head = head->next;
free(c_ptr);
}
}
