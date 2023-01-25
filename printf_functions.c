#include "main.h"

/**
* print_c - prints a char
* @c: char to print
*Return: 1
*/
int print_c(va_list c)
{
	_putchar(va_arg(c, int));
	return (1);
}

/**
 * print_s - prints a string
 * @s: string to print
 *Return: len
 */
int print_s(va_list s)
{
	int len;

	char *str = (va_arg(s, char *));

	if (str != NULL)
	{
		len	= _strlen(str);

		write(1, str, len);
	}
	else
	{
		str = "(null)";

		write(1, str, 6);
	}
	return (len);
}
/**
 *print_per - Print percent.
 *@p: integer
 *Return: integer
 */
int print_per(va_list p)
{
	(void) p;
	_putchar('%');
	return (1);
}
/**
 *print_di - print
 *@di: di
 *Return: di
 */
int print_di(va_list di)
{
	long int num = 0;
	int cuen = 0;
	long int b = 0;
	long int c = 1;

	num = va_arg(di, int);
	if (num < 0)
	{
		_putchar('-');
		num = num * (-1);
		cuen = 1;
	}
	while (c <= num)
	{
		c = c * 10;
	}
	c = c / 10;
	b = num;
	while (c > 0)
	{
		b = num / c;
		_putchar((b % 10) + '0');
		c = c / 10;
		cuen = cuen + 1;
	}
	if (num == 0)
	{
		_putchar(0 + 48);
		cuen = cuen + 1;
	}
	return (cuen);
}
