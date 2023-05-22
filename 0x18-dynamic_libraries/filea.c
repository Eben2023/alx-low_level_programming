#include "maina.h"

/**
 * is_prime - Check if a number is prime.
 * @num: The number to check.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime(int num)
{
if (num <= 1)
return (0);

for (int i = 2; i * i <= num; i++)
{
if (num % i == 0)
return (0);
}

return (1);
}

/**
 * print_primes - Print prime numbers from start to end.
 * @start: The starting number.
 * @end: The ending number.
 */
void print_primes(int start, int end)
{
printf("Prime numbers from %d to %d:\n", start, end);

for (int i = start; i <= end; i++)
{
if (is_prime(i))
printf("%d ", i);
}

printf("\n");
}

/**
 * print_fibonacci - Print the Fibonacci series from a to b.
 * @a: The starting number.
 * @b: The ending number.
 */
void print_fibonacci(int a, int b)
{
printf("Fibonacci series from %d to %d:\n", a, b);

int first = a;
int second = a <= 1 ? 1 : a;

printf("%d %d ", first, second);

int next;
while ((next = first + second) <= b)
{
printf("%d ", next);
first = second;
second = next;
}

printf("\n");
}
