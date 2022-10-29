#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_printf(const char *str, ...);
void	ft_putstr(const char *s,int *ret);
void	ft_putnbr(int n,int *ret);
char	*ft_itoa(int n);
void	ft_putchar(char c,int *ret);
void ft_printmem(void *p,int *ret);
void printvariable(int flag,va_list variables,int *ret);
void hexupp(unsigned long int nbr,int *ret);
void hexlow(unsigned long int nbr,int *ret);
void ft_unsgndnbr(int num,int *ret);

#endif