#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: Pointing to a string of 0 and 1 chars
 *
 * Return: Converted number
 **/

unsigned int binary_to_uint(const char *b)
{
int i;
unsigned int number = 0;

if (!b)
return (0);


for (i = 0; b[i] != '\0'; i++)
{

if (b[i] == '0')
{
number = number << 1;
}

else if (b[i] == '1')
{
number = (number << 1) | 1;
}

else
{
return (0);
}
}
return (number);
}

