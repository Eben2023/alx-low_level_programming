#include "main.h"

/**
 * get_endianness - Checks for endianness
 *
 * Return: If big endian return 0 else 1
 **/

int get_endianness(void)
{
int number = 1;
char *endian = (char *)&number;

if (*endian == 1)
{
return (1);
}
else if (*endian == 0)
{
return (0);
}
else
{
return (-1);
}
}
