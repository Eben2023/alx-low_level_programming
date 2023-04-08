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
unsigned long int select_bit = 1;
int x;

if (index >= sizeof(unsigned long int) * 8)
{
return (-1);
}

for (x = 0; x < index; x++)
{
select_bit <<= 1;
}

*n &= ~select_bit;

return (1);
}