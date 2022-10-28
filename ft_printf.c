#include "ft_printf.h"



int findflagpos(const char *str)
{
	if(*str == '%' && *(str + 1) == 'c')
		return 1;
	if(*str == '%' && *(str + 1) == 's')
		return 2;
	if(*str == '%' && *(str + 1) == 'p')
		return 3;
	if(*str == '%' && *(str + 1) == 'd')
		return 4;
	if(*str == '%' && *(str + 1) == 'i')
		return 5;
	if(*str == '%' && *(str + 1) == 'u')
		return 6;
	if(*str == '%' && *(str + 1) == 'x')
		return 7;
	if(*str == '%' && *(str + 1) == 'X')
		return 8;
	if(*str == '%' && *(str + 1) == '%')
		return 9;
	if(*str == '%')
		return 10;
	return (0);
}



int ft_printf(const char *str,...)
{
	va_list variables;
	va_start(variables,str);
	while(*str)
	{	
		if(findflagpos(str) > 0 && findflagpos(str) <= 9)
		{
			printvariable(findflagpos(str),variables);
			str += 2;
		}
		if(findflagpos(str)  == 10)
			str++;
		else 
		{
			ft_putchar(*str);
			str++;
		}
	
	}
	va_end(variables);
	return 0;
}

void printvariable(int flag,va_list variables)
{
	if (flag == 1)
		ft_putchar(va_arg(variables,int));
	if (flag == 2)
		ft_putstr(va_arg(variables,char*));
	if (flag == 4)
		ft_putnbr(va_arg(variables,int));
	if (flag == 7)
		hexlow(va_arg(variables,int));
	if (flag == 8)
		hexupp(va_arg(variables,int));
	if (flag == 5)
		ft_putnbr(va_arg(variables,int));
	if (flag == 3)
		ft_printmem(va_arg(variables,void *));
	if (flag == 6)
		ft_unsgndnbr(va_arg(variables,int));
	if (flag == 9)
		ft_putchar('%');
}


int main()
{
	//int d = -2114564256;
	ft_printf("%s\n","test");
	printf("dsfan,ds.f || %s","test");
	return 0;
}