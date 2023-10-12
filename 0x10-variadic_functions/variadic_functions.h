#ifndef VAR_FUNC_H
#define VAR_FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*0. Beauty is variable, ugliness is constant*/
int sum_them_all(const unsigned int n, ...);

/*1. To be is to be the value of a variable*/
void print_numbers(const char *separator, const unsigned int n, ...);

/*2. One woman's constant is another woman's variable*/
void print_strings(const char *separator, const unsigned int n, ...);

/*3. To be is a to be the value of a variable*/
void print_all(const char * const format, ...);

#endif
