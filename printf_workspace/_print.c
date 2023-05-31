#include "main.h"

/**
 * _printf - generates output which complies with a format
 * @format: a format string with the specified characters and specifiers
 * calc: the count 
 * Description: this function will call the get_print() function, which will 
 * choose the appropriate printing function based on the conversion specifiers 
 * present in fmt.
 *
 * Return: the formatted output string's length
 * Project team: Gabriella and Gabeebah
 *
 */

int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, g.flags_t *);
	const char *p;
	va_list ap;
	g.flags_t g.flags = FLAG_SHIPS;
	FLAG_SHIPS = {0, 0, 0};
            register int calc = 0;

va_start(ap, format);
if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				calc += _putchar('%');
                                                          continue;
			}
			while (get_g.flags(*p, &g.flags))
				p++;
			calc += (pfunc)
				? pfunc(ap, &g.flags)
				: _printf("%%%c", *p);

                                           pfunc = get_print(*p);
			
		  }else
			calc += _putchar(*p);
	}
               _putchar(BUF_F);
	va_end(ap);
	return (calc);
}
