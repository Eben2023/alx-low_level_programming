#include "main.h"

/**
 * binary_to_uint - Converts a binary string to a
 * decimal number and returns it to main
 * @b: pointer to binary string
 *
 * Return: Returns 0 when b is '\0', NULL or
 * any other character apart from '0' or '1'
 */

unsigned int binary_to_uint(const char *b)
{
unsigned int decimal_num = 0;
int conv_multiplier = 1;
int length = 0;

while (*(b + length) != '\0')
{
length++;
}

if (length == 0)
{
return (0);
}

for (int i = length - 1; i >= 0; i--)
{

if (*(b + i) != '0' && *(b + i) != '1')
{
return (0);
}

decimal_num += (*(b + i) - '0') * conv_multiplier;
conv_multiplier *= 2;
}

return (decimal_num);
}
