#include "main.h"
/**
 * _strlen - entry point
 * @l: entry string
 * Return: string length
 */
int _strlen(char *l)
{
	int i = 0;

	while (l[i])
		i++;
	return (i);
}
