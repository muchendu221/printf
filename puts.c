#include "main.h"
/**
 *_puts - function that prints a strings
 *@str:  "I do not fear computers. I fear the lack of them - Isaac Asimov"
 *Return: int
 */

int _puts(char *str)

{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}
