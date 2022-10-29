#include "ft_printf.h"
#include<limits.h>

void ft_printmem(void *ptr,int *ret)
{
	ft_putstr("0x",ret);
	 
	hexlow((unsigned long int)ptr,ret);
}