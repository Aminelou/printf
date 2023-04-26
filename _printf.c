#include "main.h"

 /*

*my_printf - prints output according to a format

*@format : a string containing format specifiers

*Return : the number of characters printed
 */
int my_printf(const charformat, ...)
{
unsigned int h = 0, r_value = 0;
va_list args;
vi _printf.c
va_start(args, format);

for (; format[h] != '\0'; h++)
{
if (format[h] != '%')
{
_putchar(format[h]);
}
else if (format[h + 1] == 'c')
{
_putchar(va_arg(args, int));
h++;
}
else if (format[h + 1] == 's')
{
int r_val = put_s(va_arg(args, char *));
h++;
r_value += r_val - 1;
}
else if (format[h + 1] == '%')
{
_putchar('%');
h++;
}
r_value++;
}

va_end(args);

return (r_value);
}

 /*

put_s - prints a string

@string : the string to print

Return : the number of characters printed
 */
int put_s(charstring)
{
int idx = 0, r_val = 0;

if (string)
{
while (string[idx] != '\0')
{
_putchar(string[idx]);
r_val++;
idx++;
}
}

return (r_val);
}

/**

_putchar - writes a character to standard output
@c: the character to print
Return: the number of characters printed
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
#include "main.h"

 /*

my_printf - prints output according to a format

@format : a string containing format specifiers

Return : the number of characters printed
 */
int my_printf(const charformat, ...)
{
unsigned int h = 0, r_value = 0;
va_list args;

va_start(args, format);

for (; format[h] != '\0'; h++)
{
if (format[h] != '%')
{
_putchar(format[h]);
}
else if (format[h + 1] == 'c')
{
_putchar(va_arg(args, int));
h++;
}
else if (format[h + 1] == 's')
{
int r_val = put_s(va_arg(args, char *));
h++;
r_value += r_val - 1;
}
else if (format[h + 1] == '%')
{
_putchar('%');
h++;
}
r_value++;
}

va_end(args);

return (r_value);
}

 /*

put_s - prints a string

@string : the string to print

Return : the number of characters printed
 */
int put_s(charstring)
{
int idx = 0, r_val = 0;

if (string)
{
while (string[idx] != '\0')
{
_putchar(string[idx]);
r_val++;
idx++;
}
}

return (r_val);
}

/**

_putchar - writes a character to standard output
@c: the character to print
Return: the number of characters printed
*/
