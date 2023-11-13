#include "main.h"

/* Unsigned number */

/**
 * print_unsigned - print a unsigne number
 * @types: input
 * @buffer: input
 * @flags: input
 * @width: input
 * @precision: input
 * @size: input
 * Return: num of chars
 */

int print_unsigned(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


/* Unsigned number octal */

/**
 * print_octal - print unsigned in octal
 * @types: input
 * @buffer: input
 * @flags: input
 * @width: input
 * @precision: input
 * @size: input
 * Return: num of chars
 */

int print_octal(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* unsigned num in hexa */

/**
 * print_hexadecimal - print unsigned in hexadecimal
 * @types: input
 * @buffer: input
 * @flags: input
 * @width: input
 * @precision: input
 * @size: input
 * Return: num of chars
 */

int print_hexadecimal(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	return (print_hexa(types, "0123456789abcdefgh", buffer, flags,
	'x', width, precision, size));
}

/* print unsigned in upper hexa */

/**
 * print_hexa_upper - print unsigned in upper hexa
 * @types: input
 * @buffer: input
 * @flags: input
 * @width: input
 * @precision: input
 * @size: input
 * Return: num of chars
 */

int print_hexa_upper(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEFGH", buffer, flags,
	'x', width, precision, size));
}

/* print hexa num in lower or upper */

/**
 * print_hexa - print hexa num in lower or upper
 * @types: input
 * @map_to: input
 * @buffer: input
 * @flags: input
 * @flag_ch: input
 * @width: input
 * @precision: input
 * @size: input
 * @sizee: input
 * Return: num of char
 */

int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

