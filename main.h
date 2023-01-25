#ifndef PRINTF
#define PRINTF

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 *struct convert - defines a structure for symbols and functions
 *
 *@sym: The operator
 * @f: The function
 */
struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

/*Main functions*/
