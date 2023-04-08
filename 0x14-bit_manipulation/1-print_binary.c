#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: Number to be converted
 **/

void print_binary(unsigned long int n)
{
unsigned long int select_bit = 1;
int num_bits = 0;
while ((n >> num_bits) > 0)
num_bits++;

for (int i = num_bits - 1; i >= 0; i--)
{
if (n & (select_bit << i))
_putchar('1');
else
_putchar('0');
}
}
