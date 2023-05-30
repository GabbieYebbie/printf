#include "main.h"

/**
 * print_char -It  prints a char
 * print_string - It prints a string
* print_percent - It prints a percent sign
  * print_int - Print int
  * print_binary - Prints an unsigned number
  * @types: List a of arguments
  * @buffer: Buffer array to handle print
  * @gabs:  Calculates active gabs
  * @width: represents the width
  * @precision: specifies the precision
 * @size: specifies the size
 * Return: The total of chars printed
 */
int print_char(va_list types, char buffer[],
	int gabs, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, gabs, width, precision, size));
}
 
int print_string(va_list types, char buffer[],
	int gabs, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(gabs);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (gabs & MINUS_FLAG)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}


int print_percent(va_list types, char buffer[],
	int gabs, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(gabs);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

int print_int(va_list types, char buffer[],
	int gabs, int width, int precision, int size)
{
	int i = BUFF_SIZE_OUTPUT - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE_OUTPUT - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, gabs, width, precision, size));
}


 
int print_binary(va_list types, char buffer[],
	int gabs, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int sum;

	UNUSED(buffer);
	UNUSED(gabs);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, sum = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			sum++;
		}
	}
	return (sum);
}