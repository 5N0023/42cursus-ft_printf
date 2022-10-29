#include "ft_printf.h"

void hexlow(unsigned long int num,int *ret)
{   
	if (num <= 15)
		ft_putchar("0123456789abcdef"[num],ret);
	else if (num > 15)
	{
		hexlow(num/16,ret);
		hexlow(num%16,ret);
	}
}
void hexupp(unsigned long int num,int *ret)
{   
	if (num <= 15)
		ft_putchar("0123456789ABCDEF"[num],ret);
	else if (num > 15)
	{
		hexupp(num/16,ret);
		hexupp(num%16,ret);
	}
}