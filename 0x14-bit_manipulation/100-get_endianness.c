#include "main.h"

/**
 * get_endianness - Checks for endianness
 *
 * Return: If big endian return 0 else 1
 **/

int get_endianness(void)
{
int num = 1;
char *endian;
int i;

endian = (char *)malloc(sizeof(char));

if (endian == NULL)
{

return (-1);
}

for (i = 0; i < sizeof(int); i++)
{
if (i == 0)
{
*endian = (char)num;
}
else
{
*endian = (char)(num >> (i * 8));
}
}

if (*endian == 1)
{
free(endian);
return (1);
}
else
{
free(endian);
return (0);
}
}
