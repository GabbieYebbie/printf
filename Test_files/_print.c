#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
  int calc = 0, i;
  
  va_list data;
  va_start(data, format);

  /* _printf("%s", 'Hello') */
  
  for (i = 0; format[i] != '\0'; ){
    
    /* calculate the number of characters */
    /* print each character counted on the screen */
    if (format[i] != '%'){
      calc += _putchar(format[i]);
      i++;
    }
    else if (format[i] == '%' && format[i+1] !=' '){
      switch (format[i + 1]){
        case 'c':
            /* print the character from the va_ap */
            calc += _putchar(va_arg(data, int));
            break;
        case 's':
            calc += print_string(va_arg(data, char *));
            break;
        case '%':
            /* print the character from the va_ap */
            calc += _putchar('%');
            break;
        case 'd':
            calc += print_decimal(va_arg(data, int));
            break;
        case 'i':
            calc += print_decimal(va_arg(data, int));
            break;
        case 'b':
            calc += print_binary(va_arg(data, int));
            break;
        case 'u':
            calc += print_unsigned(va_arg(data, unsigned int));
            break;
        default:
            break;
      }
      
      i += 2;
    }
    
    
  }
  

  return (calc);
}
