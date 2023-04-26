#include <stdio.h>
#include <string.h>
/**

_putchar - writes a character to standard output
@c: the character to print
Return: the number of characters printed
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
