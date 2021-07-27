#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_unsigned - prints unsigned integer
 *
 * @arg_list: arguments list
 *
 * Return: number
 */

int print_unsigned(va_list arg_list)
{
int divisor = 1, i, resp;
unsigned int n = va_arg(arg_list, unsigned int);
for (i = 0; n / divisor > 9; i++, divisor *= 10)
;
for (; divisor >= 1; n %= divisor, divisor /= 10)
{
	resp = n / divisor;
	_putchar('0' + resp);
}
return (i + 1);
}



/**
 * print_octal - prints a hexadecimal
 * @arg_list: list that contains the hexadecimal
 * Return: number.
 */
int print_octal(va_list arg_list)
{
	unsigned int num = va_arg(arg_list, unsigned int);
	unsigned int copia;
	char *octa;
	int i, s = 0, print_count = 0;

	if (num == 0)
		return (_putchar('0'));
	for (copia = num; copia != 0; s++)
	{
		copia = copia / 8;
	}
	octa = malloc(s);
	if (!octa)
		return (-1);
	for (i = s - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}
	for (i = 0; i < s && octa[i] == '0'; i++)
		;
	for (; i < s; i++)
	{
		_putchar(octa[i]);
		print_count++;
	}
	free(octa);
	return (print_count);
}


/**
 * print_unsignedTobinary - function that prints the binary
 * representation of a number
 * @num: num
 * Return: binary number
 */

int print_unsignedTobinary(int num)
{
	if (num < 2)
		return (num);
	return (print_unsignedTobinary(num / 2) * 10 + num % 2);
}


/**
 * print_binary - function that prints the binary
 * representation of a number
 * @arg_list: argument list
 * Return: number of charachters printed
 */


int print_binary(va_list arg_list)
{
	int num = va_arg(arg_list, int), print_count = 0, result;
	char *str;

	result = print_unsignedTobinary(num);
	str = inttostr(result);

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		if (*str == 0 || (*str > 31 && *str < 127))
			print_count++;
	}
	return (print_count);
}
