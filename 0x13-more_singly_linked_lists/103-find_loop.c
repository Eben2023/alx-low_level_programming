#include <stdlib.h>
#include "lists.h"

/**
 * detect_loop - detect and return the node where the loop starts 
 * in a linked list
 * @head: head of the linked list to search for
 *
 * Return: the node where the loop starts, or NULL if there's no loop
 */
listint_t *detect_loop(listint_t *head)
{
if (!head)
return NULL;

listint_t *slow = head, *fast = head->next;

while (fast != NULL && fast->next != NULL && slow != fast)
{
slow = slow->next;
fast = fast->next->next;
}

if (slow != fast)
{
return NULL;
}

slow = head;
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}

return fast;
}
