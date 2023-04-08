#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: Number to be converted
 **/

void print_binary(unsigned long int n)
{
unsigned long int val_n = 1ul << (sizeof(unsigned long int) * 8 - 1);
int check = 0;
while (val_n)
{
if (n & val_n)
{
putchar('1');
check = 1;
}
else if (check)
{
putchar('0');
}
val_n >>= 1;
}
if (!check)
{
putchar('0');
}
}
