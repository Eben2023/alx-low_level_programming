#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index
 * @n: Number
 * @index: Index to set
 * Return: 1 for success, else -1
 **/

int set_bit(unsigned long int *n, unsigned int index)
{
unsigned long int select_bit = 1;

if (index >= sizeof(unsigned long int) * 8)
{
return (-1);
}

select_bit = select_bit << index;

*n = *n | select_bit;

return (1);
}
