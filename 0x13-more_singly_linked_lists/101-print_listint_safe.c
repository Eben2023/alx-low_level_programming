#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t list safely
 * @head: A pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;
const listint_t *temp = head;

while (temp != NULL)
{
printf("[%p] %d\n", (void *)temp, temp->n);
count++;
if (temp <= temp->next)
{
fprintf(stderr, "Error: loop detected in list\n");
exit(98);
}
temp = temp->next;
}

return (count);
}

