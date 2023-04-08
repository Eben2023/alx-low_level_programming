/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print.
 */

void print_binary(unsigned long int n)
{
if (n > 1)
{
print_binary(n >> 1);
}

int bit_value = n & 1;
char ch = '0' + bit_value;
_putchar(ch);
}
