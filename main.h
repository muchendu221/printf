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
int parser(const char *format, conver_t f_list[], va_list arg_list);
int _printf(const char *format, ...);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);

/* helper functions*/
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy( char *dest, char *src, unsigned int n);
int print_unsigned_number(unsigned int);


#endif
