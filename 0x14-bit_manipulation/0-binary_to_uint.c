#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned int
 * @b: Pointing to a string of 0 and 1 chars
 *
 * Return: The converted convert_num, or 0 when b is NULL or not 0 or 1
 **/

unsigned int binary_to_uint(const char *b)
{
int i = 0;
unsigned int convert_num = 0;

if (!b)
{
return (0);
}

for (i = 0; b[i] != '\0'; i++)
{

if (b[i] == '0')
{
convert_num = convert_num << 1;
}

else if (b[i] == '1')
{
convert_num = (convert_num << 1) | 1;
}

else
{
return (0);
}
}
return (convert_num);
}
