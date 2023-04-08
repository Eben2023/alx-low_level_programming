#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @n: Number
 * @index: Position
 *
 * Return: Return 1 for succes else -1
 **/

int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= 31)
{
return (-1);
}
else
{
if (*n == 0)
{
*n = 1 << index;
}
else
{
*n = ~(1 << index) & *n;
}
return (1);
}
}
