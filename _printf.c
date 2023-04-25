#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int j, printed = 0, printed_ch = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_index++] = format[j];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			/* write(1, &format[j], 1);*/
			printed;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_precision(format, &j, list);
			size = get_size(format, &j);
			++j;
			printed = handle_print(format, &j, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_ch += printed;
		}
		if (*format[j] == '%')
		{
			printed_ch++;
			if (*format[j] == 'c')
			{
				char c = va_arg(list, int);

				printed += _putchar(c);
				printed_ch++;
			}
			else if (*format[j] == 's')
			{
				char *str = va_arg(list, char *);

				printed += handle_print(str);
				printed_ch++;
			}
			else if (*format[j] == '%')
			{
				_putchar('%');
				printed_ch++;
			}
		}
	}
	print_buffer(buffer, &buff_index);

	va_end(list);

	return (printed_ch);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_index: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
