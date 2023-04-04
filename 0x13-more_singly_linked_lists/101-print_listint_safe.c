#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * main - Entry point, runs some tests on print_listint_safe.
 *
 * Return: Always 0.
 */
int main(void)
{
listint_t *head;
listint_t *node;

head = NULL;
node = add_nodeint(&head, 0);
add_nodeint(&head, 1);
add_nodeint(&head, 2);
add_nodeint(&head, 3);
add_nodeint(&head, 4);
add_nodeint(&head, 5);
add_nodeint(&head, 6);
add_nodeint(&head, 7);
add_nodeint(&head, 8);
add_nodeint(&head, 9);
node->next = add_nodeint(&head, 10);

printf("Nodes in the list = %lu\n", print_listint_safe(head));
free_listint_safe(&head);

head = NULL;
node = add_nodeint(&head, 0);
add_nodeint(&head, 1);
add_nodeint(&head, 2);
add_nodeint(&head, 3);
add_nodeint(&head, 4);
add_nodeint(&head, 5);
add_nodeint(&head, 6);
add_nodeint(&head, 7);
add_nodeint(&head, 8);
add_nodeint(&head, 9);
add_nodeint(&head, 10);

printf("Nodes in the list = %lu\n", print_listint_safe(head));
free_listint_safe(&head);

head = NULL;
node = add_nodeint(&head, 0);

printf("Nodes in the list = %lu\n", print_listint_safe(head));
free_listint_safe(&head);

head = add_nodeint(&head, 0);
node = add_nodeint(&head, 1);
node->next = head;

printf("Nodes in the list = %lu\n", print_listint_safe(head));
free_listint_safe(&head);

return (0);
}

/**
 * looped_listint_len - Counts the number of unique nodes
 *  in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
const listint_t *tortoise, *hare;
size_t nodes = 1;

if (head == NULL || head->next == NULL)
return (0);

tortoise = head->next;
hare = (head->next)->next;

while (hare)
{
if (tortoise == hare)
{
tortoise = head;
while (tortoise != hare)
{
nodes++;
tortoise = tortoise->next;
hare = hare->next;
}

tortoise = tortoise->next;
while (tortoise != hare)
{
nodes++;
tortoise = tortoise->next;
}

return (nodes);
}

tortoise = tortoise->next;
hare = (hare->next)->next;
}

return (0);
}
