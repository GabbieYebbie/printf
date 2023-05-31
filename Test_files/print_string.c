#include "main.h"

int print_string(char *string){
  int calc = 0;

  for (int i = 0; string[i] != '\0'; i++){
    calc += _putchar(string[i]);
  }
  
  return (calc);
}
