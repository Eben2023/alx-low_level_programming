#include "main.h"

/**
 * get_bit - Sets the value of a bit to 1 at an index
 * @n: Number base
 * @index: Index to implement change
 *
 * Return: 1 if succesful or -1 if failed
 **/

int get_bit(unsigned long int n, unsigned int index)
{
unsigned long int mask = 1;

if (index >= sizeof(unsigned long int) * 8)
{
return (-1);
}

mask = mask << index;

if ((n & mask) == 0)
{
return (0);
}
else
{
return (1);
}
}
