#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned integer.
 * @b: A pointer to a string of 0's and 1's.
 * Return: The unsigned integer value of the binary string.
 */

unsigned int binary_to_uint(const char *b)
{
int a;
unsigned int number = 0;

if (!b)
{
return (0);
}
for (a = 0; b[a] != '\0'; a++)
{
if (b[a] != '0' && b[a] != '1')
return (0);
}

for (a = 0; b[a] != '\0'; a++)
{
number = number << 1;

if (b[a] == '1')
{
number = number | 1;
}
}

return (number);
}

