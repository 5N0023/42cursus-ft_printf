#include "ft_printf.h"

void hexlow(long nbr)
{   
    unsigned long num = nbr;

	if (num <= 15)
		ft_putchar("0123456789abcdef"[num]);
	else if (num > 15)
	{
		hexlow(num/16);
		hexlow(num%16);
	}
}
void hexupp(long nbr)
{   
    unsigned long num = (unsigned)nbr;

	if (num <= 15)
		ft_putchar("0123456789ABCDEF"[num]);
	else if (num > 15)
	{
		hexupp(num/16);
		hexupp(num%16);
	}
}