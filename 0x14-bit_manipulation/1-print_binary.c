#include "main.h"

/**
 * binary_to_uint - Converts a binary to an unsigned int.
 * @b: Pointer to a string of 0 and 1 chars.
 *
 * Return: The converted number
 */

unsigned int binary_to_uint(const char *b)
{
unsigned int bin_number = 0;
unsigned int factor = 1;
int len = 0;

if (b == NULL)
return (0);

while (b[len] != '\0')
len++;

for (int i = len - 1; i >= 0; i--)
{
if (b[i] != '0' && b[i] != '1')
return (0);

if (b[i] == '1')
bin_number += factor;

factor *= 2;
}

return (bin_number);
}
