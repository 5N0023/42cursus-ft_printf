/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:37:49 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/01 00:28:57 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_putchar(char c, int *ret)
{
	if (write(1, &c, 1) == -1)
	{
		*ret = -1;
		return ;
	}
	*ret += 1;
}

void	ft_putstr(const char *s, int *ret)
{
	size_t	i;

	if (!s)
	{
		ft_putstr("(null)", ret);
		return ;
	}
	i = 0;
	while (s[i] && *ret != -1)
	{
		ft_putchar(s[i], ret);
		i++;
	}
}

void	ft_putnbr(int n, int *ret)
{
	char	*nbr;

	nbr = ft_itoa(n, ret);
	ft_putstr(nbr, ret);
	free(nbr);
}

void	ft_unsgndnbr(unsigned int num, int *ret)
{
	if (num < 10 && *ret != -1)
		ft_putchar(num + '0', ret);
	else
	{
		ft_unsgndnbr(num / 10, ret);
		ft_unsgndnbr(num % 10, ret);
	}
}
