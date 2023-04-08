#include "main.h"

/**
 * flip_bits - Counts the number of bits you would need to flip a bit
 * @n: Number
 * @m: Number
 *
 * Return: Number count
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int xor = n ^ m;
unsigned long int y = 0;
unsigned long int x = 1;

while (x > 0)
{
if (xor & x)
{
y++;
}

x <<= 1;
}

return (y);
}
