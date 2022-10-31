/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexaform.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:37:35 by mlektaib          #+#    #+#             */
/*   Updated: 2022/10/31 23:36:24 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexlow(unsigned long int num, int *ret)
{
	if (num <= 15 && *ret != -1)
		ft_putchar("0123456789abcdef"[num], ret);
	else if (num > 15 && *ret != -1)
	{
		hexlow(num / 16, ret);
		hexlow(num % 16, ret);
	}
}

void	hexupp(unsigned long int num, int *ret)
{
	if (num <= 15 && *ret != -1)
		ft_putchar("0123456789ABCDEF"[num], ret);
	else if (num > 15 && *ret != -1)
	{
		hexupp(num / 16, ret);
		hexupp(num % 16, ret);
	}
}

void	ft_printmem(void *ptr, int *ret)
{
	ft_putstr("0x", ret);
	hexlow((unsigned long int)ptr, ret);
}
