#include "main.h"

/**
 * get_flags - prints the contents of the buffer if it exist
 *
 * @format: array of char.
 * @par: a parameter.
 *
 * Return: flags
 */

int get_flags(const char *format, int *par)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */

	int j, i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (i = *par + 1; format[i] != '\0'; i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
			if (FLAGS_CH[j] == 0)
				break;
		}
	}
	*par = i - 1;
	return (flags);
}
