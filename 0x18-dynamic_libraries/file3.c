#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string to be appended.
 *
 * Return: Pointer to the resulting string.
 */
char *_strcat(char *dest, char *src)
{
char *dest_start = dest;

while (*dest)
{
dest++;
}

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
 * _strncat - Concatenates two strings, using at most n bytes from src.
 * @dest: The destination string.
 * @src: The source string to be appended.
 * @n: The maximum number of bytes from src to be used.
 *
 * Return: Pointer to the resulting string.
 */
char *_strncat(char *dest, char *src, int n)
{
char *dest_start = dest;

while (*dest)
{
dest++;
}

while (*src && n > 0)
{
*dest = *src;
dest++;
src++;
n--;
}

*dest = '\0';

return (dest_start);
}

/**
 * _strncpy - Copies a string, using at most n bytes from src.
 * @dest: The destination buffer.
 * @src: The source string to be copied.
 * @n: The maximum number of bytes from src to be used.
 *
 * Return: Pointer to the destination string.
 */
char *_strncpy(char *dest, char *src, int n)
{
char *dest_start = dest;

while (*src && n > 0)
{
*dest = *src;
dest++;
src++;
n--;
}

while (n > 0)
{
*dest = '\0';
dest++;
n--;
}

return (dest_start);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is
 *         found, respectively, to be less than, to match, or be greater
 * than s2.
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && (*s1 == *s2))
{
s1++;
s2++;
}

return (*s1 - *s2);
}

/**
 * _memset - Fills the first n bytes of the memory area pointed to by s
 *           with the constant byte b.
 * @s: The memory area to be filled.
 * @b: The constant byte to fill the memory area with.
 * @n: The number of bytes to be filled.
 *
 * Return: Pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
char *start = s;

while (n > 0)
{
*s = b;
s++;
n--;
}

return (start);
}
