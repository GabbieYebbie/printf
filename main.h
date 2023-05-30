#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE_OUTPUT 1024
#define BUF_F -1

/* GABS */
#define MINUS_FLAG 1
#define PLUS_FLAG 2
#define ZERO_FLAG 4
#define HASH_FLAG 8
#define SPACE_FLAG 16

/* SIZE */
#define SHORT_SIZE 1
#define LONG_SIZE 2

#define GABS_STARS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
        char fmt;
        int (*fn)(va_list, char[], int, int, int, int);
};

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
	int gabs, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int gabs, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int gabs, int width, int precision, int size);
int print_int(va_list types, char buffer[],
	int gabs, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int gabs, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int gabs, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int gabs, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int gabs, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int gabs, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int gabs, char flag_ch, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[],
	int gabs, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
	int gabs, int width, int precision, int size);
int get_gabs(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int print_reverse(va_list types, char buffer[],
	int gabs, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[],
	int gabs, int width, int precision, int size);
int handle_write_char(char c, char buffer[],
	int gabs, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int gabs, int width, int precision, int size);
int write_num(int ind, char bff[], int gabs, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int gabs, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int gabs, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif