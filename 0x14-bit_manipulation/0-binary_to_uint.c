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
unsigned int num = 0;

if (b == NULL)
{
return (0);
}

for (int i = 0; b[i] != '\0'; i++)
{
if (b[i] == '0')
{
num = num * 2;
}
else if (b[i] == '1')
{
num = num * 2 + 1;
}
else
{
return (0);
}
}

return (num);
}
