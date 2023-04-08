#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: Number to be converted
 **/

void print_binary(unsigned long int n)
{
unsigned long int mask = 1ul << (sizeof(unsigned long int) * 8 - 1);
int flag = 0;
while (mask)
{
if (n & mask)
{
putchar('1');
flag = 1;
}
else if (flag)
{
putchar('0');
}
mask >>= 1;
}
if (!flag)
{
putchar('0');
}
}
