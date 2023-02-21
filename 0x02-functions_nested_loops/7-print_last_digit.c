#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @p: The int to extract the last digit from
 * Return: value of the last digit
 */

int print_last_digit(int p)
{
int b;
if (p < 0)
	p = -p;
b = p % 10;
if (b < 0)
	b = -b;
_putchar(b + '0');
return (b);
}
