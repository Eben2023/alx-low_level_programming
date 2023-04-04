#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 *
 * @h: A pointer to the head of the listint_t list.
 *
 * Return: The size of the list that was free'd.
 */
size_t free_listint_safe(listint_t **h)
{
size_t size = 0;
listint_t *tmp, *current = *h;

while (current)
{
size++;
if (current <= current->next)
{
printf("Freeing %d\n", current->n);
tmp = current;
current = current->next;
free(tmp);
}
else
{
printf("Freeing %d\n", current->n);
free(current);
break;
}
}
*h = NULL;
return (size);
}
