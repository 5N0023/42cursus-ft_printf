#include "ft_printf.h"



int findflagpos(const char *str)
{
	if(*str == '%' && *(str + 1) == 'c')
		return 1;
	else if(*str == '%' && *(str + 1) == 's')
		return 2;
	else if(*str == '%' && *(str + 1) == 'p')
		return 3;
	else if(*str == '%' && *(str + 1) == 'd')
		return 4;
	else if(*str == '%' && *(str + 1) == 'i')
		return 5;
	else if(*str == '%' && *(str + 1) == 'u')
		return 6;
	else if(*str == '%' && *(str + 1) == 'x')
		return 7;
	else if(*str == '%' && *(str + 1) == 'X')
		return 8;
	else if(*str == '%' && *(str + 1) == '%')
		return 9;
	return (0);
}



int ft_printf(const char *str,...)
{
	va_list variables;
	va_start(variables,str);
	int ret;

	ret = 0;
	while(*str)
	{	
		if(findflagpos(str) > 0 && findflagpos(str) <= 9)
		{
			printvariable(findflagpos(str),variables,&ret);
			str += 2;
		}
		else if (*str)
		{
			ft_putchar(*str,&ret);
			str++;
		}
	}
	va_end(variables);
	return ret;
}

void printvariable(int flag,va_list variables,int *ret)
{
	if (flag == 1)
		ft_putchar(va_arg(variables,int),ret);
	else if (flag == 2)
		ft_putstr(va_arg(variables,char*),ret);
	else if (flag == 3) 
		ft_printmem(va_arg(variables,void *),ret);
	else if (flag == 4)
		ft_putnbr(va_arg(variables,int),ret);
	else if (flag == 5)
		ft_putnbr(va_arg(variables,int),ret);
	else if (flag == 6)
		ft_unsgndnbr(va_arg(variables,int),ret);
	else if (flag == 7)
		hexlow(va_arg(variables,unsigned int),ret);
	else if (flag == 8)
		hexupp(va_arg(variables,unsigned int),ret);
	else if (flag == 9)
		ft_putchar('%',ret);
}
