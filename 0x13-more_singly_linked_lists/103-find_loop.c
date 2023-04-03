#include <stdlib.h>
#include "lists.h"

/**
 * find_linked_list_loop - Finds the start of a loop in a linked list
 * @head: Pointer to the head node of the linked list
 *
 * Returns: The address of the node where the loop starts, or NULL if there is no loop
 */

listint_t *find_linked_list_loop(listint_t *head)
{
// Use two pointers to traverse the linked list
listint_t *slow_ptr = head;
listint_t *fast_ptr = head;

// If the linked list is empty
if (!head)
return NULL;

// Traverse the linked list until the pointers meet or fast_ptr reaches the end
while (slow_ptr && fast_ptr && fast_ptr->next)
{
fast_ptr = fast_ptr->next->next;
slow_ptr = slow_ptr->next;

// If the pointers meet, a loop is detected
if (fast_ptr == slow_ptr)
{
// Move slow_ptr to the start of the linked list
slow_ptr = head;

// Traverse both pointers until they meet at the loop start
while (slow_ptr != fast_ptr)
{
slow_ptr = slow_ptr->next;
fast_ptr = fast_ptr->next;
}

// Return the loop start address
return fast_ptr;
}
}

// No loop detected
return NULL;
}
