#include "palindrome.h"

/**
 * is_palindrome- check if a number is palindrome
 * @n: unsigned long number
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	unsigned long number = 0;
	unsigned long tmp = 0;
	unsigned long reserved = 0;

	number = n;
	while (n != 0)
	{
		tmp = n % 10;
		reserved = reserved * 10 + tmp;
		n = n / 10;
	}

	if (number == reserved)
		return (1);

	return (0);
}
