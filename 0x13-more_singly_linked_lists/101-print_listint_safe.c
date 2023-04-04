#include "lists.h"
#include <stdio.h>

size_t _listinloop(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * _listinloop - Counts the number of unique nodes in 
 * a looped listint_t linked list
 * @head: This is a pointer to the head of listint_t for checking
 * Return: If list is not looped return (0),
 * - Else return the number of uniqe nodes
 */

size_t _listinloop(const listint_t *head)
{
if (head == NULL || head->next == NULL)
return (0);

const listint_t *slow_main = head->next;
const listint_t *fast_main = (head->next)->next;
size_t nodes = 1;

while (fast_main != NULL && fast_main->next != NULL)
{
if (slow_main == fast_main)
{
slow_main = head;
while (slow_main != fast_main)
{
nodes++;
slow_main = slow_main->next;
fast_main = fast_main->next;
}

slow_main = slow_main->next;
while (slow_main != fast_main)
{
nodes++;
slow_main = slow_main->next;
}

return (nodes);
}

slow_main = slow_main->next;
fast_main = (fast_main->next)->next;
}

return (0);
}

/**
 * print_listint_safe - Prints the linked list safely
 * @head: Points to the head of the linked list
 * Return: Number of nodes in the linked list
 */

size_t print_listint_safe(const listint_t *head)
{
size_t nodes = _listinloop(head);

if (nodes == 0)
{
size_t index;
for (index = 0; head != NULL; index++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
nodes = index;
}
else
{
size_t index;
for (index = 0; index < nodes; index++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
printf("-> [%p] %d\n", (void *)head, head->n);
nodes = nodes + 1;
}

return (nodes);
}
