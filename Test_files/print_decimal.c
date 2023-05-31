#include "main.h"

int print_decimal(int value){
   int calc = 0;

    /* print '-' for negative numbers */
    if (value < 0) {
        calc += _putchar('-');
        value = value * -1;
    }
  
    /* The last digit of number is removed and 
    the remaining digits is printed using recursion, then print
    the last digit
 */
    if (value/10)
        calc += print_decimal(value/10);
  
    calc += _putchar(value%10 + '0');

    return (calc);
}
