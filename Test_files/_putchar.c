#include <unistd.h>

//_putchar - function to return character to standard output
int _putchar(char g)
{
	return (write(1, &g, 1));
}
