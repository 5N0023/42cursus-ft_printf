#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_printf(const char *str, ...);
void	ft_putstr(const char *s);
void	ft_putnbr(int n);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void ft_printmem(void *p);
void printvariable(int flag,va_list variables);
void hexupp(long nbr);
void hexlow(long nbr);
void ft_unsgndnbr(int num);

#endif