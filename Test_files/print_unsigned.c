#include "main.h"

int print_unsigned(unsigned int value){
   int calc = 0;
  
    if (value/10)
        calc += print_decimal(value/10);
  
    calc += _putchar(value%10 + '0');

    return (calc);
}
