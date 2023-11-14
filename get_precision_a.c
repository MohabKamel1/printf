#include "main.h"

/**
 * get_precision - Calculating precision for printing
 * @format: formatted string
 * @i: take a parameter.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;
	while (format[curr_i] != '\0')
	{
		curr_i += 1;
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
		curr_i++;
	}

		*i = curr_i - 1;

	return (precision);
}
