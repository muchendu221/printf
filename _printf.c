#include "main.h"
#include <stdlib.h>

/**
 * _printf - prints any string with certain flags for modification
 * @format: the string of characters to write to buffer
 * Return: an integer that counts how many writes to the buffer were made
 */
int _printf(const char *format, ...)
{
	int x = 0, r = 0;
	va_list v_ls;
	buffer *buf;

	buf = buf_new();
	if (buf == NULL)
		return (-1);
	if (format == NULL)
		return (-1);
	va_start(v_ls, format);
	while (format[x])
	{
		buf_write(buf);
		if (format[x] == '%')
		{
			r = opid(buf, v_ls, format, x);
			if (r < 0)
			{
				x = r;
				break;
			}
			x += r;
			continue;
		}
		buf->str[buf->index] = format[x];
		buf_inc(buf);
		x++;
	}
	buf_write(buf);
	if (r >= 0)
		x = buf->overflow;
	buf_end(buf);
	va_end(v_ls);
	return (x);
}
