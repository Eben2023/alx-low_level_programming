#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: head node of the list
 *
 * Return: the count of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;
const listint_t *current;
long int diff;

while (head != NULL)
{
count++;
current = head;
head = head->next;
printf("[%p] %d\n", (void *)current, current->n);

diff = head - current;
if (diff <= 0)
{
printf("-> [%p] %d\n", (void *)head, head->n);
break;
}
}

return (count);
}
