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
if (index >= (sizeof(unsigned long int) * 8))
{
return (-1);
}
unsigned long int mask = ~(1ul << index);
*n = (*n & mask);
return (1);
}
