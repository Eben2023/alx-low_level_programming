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
int diff;
listint_t *temp, *current = *h;

while (current)
{
diff = current - current->next;
if (diff > 0)
{
printf("Freeing %d\n", current->n);
temp = current;
current = current->next;
free(temp);
size++;
}
else
{
printf("Freeing %d\n", current->n);
free(current);
size++;
break;
}
}

*h = NULL;
return (size);
}
