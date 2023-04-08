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
if (!(index < sizeof(unsigned long int) * 8))
{
return (-1);
}
return ((n >> index) & 1);
}
