#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE_OUTPUT_OUTPUT_OUTPUT 1024
#define BUF_F -1

/* G.FLAGS */
#define MINUS_FLAG 1
#define PLUS_FLAG 2
#define ZERO_FLAG 4
#define HASH_FLAG 8
#define SPACE_FLAG 16
#define SHORT_SIZE 1
#define LONG_SIZE 2

#define FLAG_SHIPS

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
va_list list, char buffer[], int g.flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
	int g.flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int g.flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int g.flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
	int g.flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int g.flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int g.flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int g.flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int g.flags, int width, int precision, int size);
int print_hexa_up(va_list types, char buffer[],
	int g.flags, int width, int precision, int size);

int print_hexa_lu(va_list types, char map_to[],
char buffer[], int g.flags, char flag_ch, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[],
	int g.flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
	int g.flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int print_reverse(va_list types, char buffer[],
	int g.flags, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[],
	int g.flags, int width, int precision, int size);
int handle_write_char(char g, char buffer[],
	int g.flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int g.flags, int width, int precision, int size);
int write_num(int ind, char bff[], int g.flags, int width, int precision,
	int length, char padd, char extra_g);
int write_pointer(char buffer[], int ind, int length,
	int width, int g.flags, char padd, char extra_g, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int g.flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

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


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
