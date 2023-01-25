#include "main.h"

/**
 * print_char - prints character
 * @list: list of characters to be printed
 * Return: count of arguments printed
 */
int print_char(va_list list)
{
	_putchar(va_agr(list, int));
	return (1);
}

/**
 *print_percent - prints %
 * @list:list of arguments
 * Return: count of characters printed
 */
int print_percent(_attribute_((unused))va_list list)
{
	_putchar('%');
	return (1);
}

/**
 * print_string - prints string to stdout
 * @list: list to be printed
 * Return: count of arguments to printed
 */
int print_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
