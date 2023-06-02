#include "main.h"

int print_binary(int number){
    int arr[32], i = 0, calc = 0;
    
    while (number >= 2){
        arr[i] = number%2;
        number /= 2;
        i++;
    }
    arr[i] = number;
    
    
    for (int i = 0; i >= 0; i--)
{
        calc += _putchar(arr[i] + '0');
    }

    return (calc);
}
