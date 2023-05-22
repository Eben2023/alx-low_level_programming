#include "main.h"

/**
 * _isdigit - Checks if a character is a digit.
 * @c: The character to be checked.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
if (c >= '0' && c <= '9')
return (1);
else
return (0);
}

/**
 * _strlen - Calculates the length of a string.
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
int length = 0;

while (*s)
{
length++;
s++;
}

return (length);
}

/**
 * _puts - Prints a string to stdout.
 * @s: The string to be printed.
 */
void _puts(char *s)
{
while (*s)
{
_putchar(*s);
s++;
}

_putchar('\n');
}

/**
 * _strcpy - Copies a string.
 * @dest: The destination buffer.
 * @src: The source string to be copied.
 *
 * Return: Pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
char *dest_start = dest;

while (*src)
{
*dest = *src;
dest++;
src++;
}

*dest = '\0';

return (dest_start);
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
int sign = 1;
int result = 0;
int i = 0;

if (s[0] == '-')
{
sign = -1;
i++;
}

for (; s[i] != '\0'; i++)
{
result = result * 10 + (s[i] - '0');
}

return (sign * result);
}
