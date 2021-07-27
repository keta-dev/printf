#include "holberton.h"
#include <stddef.h>
#include <stdlib.h>

/**
 *_pow - raises the number base to power power
 *@base : the base
 *@power : the power
 *Return: return the answer
 */
int _pow(unsigned int base, int power)
{
  int i, prod = 1;

  for (i = 0; i < power; i++)
    {
      prod = prod * base;
    }
  return (prod);
}


/**
 * print_memory - print's memory
 * @arg_list: arg list
 * Return: mem
 */

int print_memory(va_list arg_list)
{
  int d = va_arg(arg_list, int);

  return (d);
}


/**
 * print_STR - prints a string with a `S` (upper case) specificer
 * @arg_list: argument
 * Return: number of character printed
 */

int print_STR(va_list arg_list)
{
  char *string = va_arg(arg_list, char *);
  int print_count = 0;

  if (string == NULL)
    {
      while ("(null)"[print_count] != '\0')
	{
	  _putchar("(null)"[print_count]);
	  print_count++;
	}
    } else
    {
      while (*string != '\0')
	{
	  _putchar(*string + 32);
	  string++;
	  print_count++;
	}
    }
  return (print_count);

}


/**
 * print_rev - prints a string in reverse
 * @arg: argument from _printf
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rev(va_list arg)
{
  char *str;
  int i, count = 0;

  str = va_arg(arg, char *);
  if (str == NULL)
    str = ")llun(";
  for (i = 0; str[i]; i++)
    ;
  for (i -= 1; i >= 0; i--)
    {
      _putchar(str[i]);
      count++;
    }
  return (count);
}


/**
 * print_R - prints a string in rot13
 * @arg: string to print
 *
 * Return: number of chars printed
 */
int print_R(va_list arg)
{
  register short i, j;
  char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
  char *s = va_arg(arg, char *);

  if (!s)
    {
      return (-1);
    }

  for (j = 0; s[j]; j++)
    {
      if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
	_putchar(s[j]);
      else
	{
	  for (i = 0; i <= 52; i++)
	    if (s[j] == rot13[i])
	      _putchar(ROT13[i]);
	}
    }
  return (j);
}
