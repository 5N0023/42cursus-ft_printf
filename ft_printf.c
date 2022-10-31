/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:37:00 by mlektaib          #+#    #+#             */
/*   Updated: 2022/10/31 23:33:09 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	findflagpos(const char *format)
{
	if (*format == '%' && *(format + 1) == 'c')
		return (1);
	else if (*format == '%' && *(format + 1) == 's')
		return (2);
	else if (*format == '%' && *(format + 1) == 'p')
		return (3);
	else if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		return (4);
	else if (*format == '%' && *(format + 1) == 'u')
		return (5);
	else if (*format == '%' && *(format + 1) == 'x')
		return (6);
	else if (*format == '%' && *(format + 1) == 'X')
		return (7);
	else if (*format == '%' && *(format + 1) == '%')
		return (8);
	else if (*format == '%')
		return (9);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	variables;
	int		ret;

	va_start(variables, format);
	ret = 0;
	while (*format && ret != -1)
	{	
		if ((findflagpos(format) > 0 && findflagpos(format) < 9) && ret != -1)
		{
			printvariable(findflagpos(format), variables, &ret);
			format += 2;
		}
		else if (findflagpos(format) == 9)
			format++;
		else if (*format)
		{
			ft_putchar(*format, &ret);
			format++;
		}
	}
	va_end(variables);
	return (ret);
}

void	printvariable(int flag, va_list variables, int *ret)
{
	if (flag == 1)
		ft_putchar(va_arg(variables, int), ret);
	else if (flag == 2)
		ft_putstr(va_arg(variables, char *), ret);
	else if (flag == 3)
		ft_printmem(va_arg(variables, void *), ret);
	else if (flag == 4)
		ft_putnbr(va_arg(variables, int), ret);
	else if (flag == 5)
		ft_unsgndnbr(va_arg(variables, int), ret);
	else if (flag == 6)
		hexlow(va_arg(variables, unsigned int), ret);
	else if (flag == 7)
		hexupp(va_arg(variables, unsigned int), ret);
	else if (flag == 8)
		ft_putchar('%', ret);
}
