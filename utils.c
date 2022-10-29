#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
void	ft_putchar(char c,int *ret)
{
	write(1, &c, 1);
	*ret += 1;
}
void	ft_putstr(const char *s,int *ret)
{
	size_t	i;

	if (!s)
	{
		ft_putstr("(null)",ret);
		return;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i],ret);
		i++;
	}
}

void	ft_putnbr(int n,int *ret)
{
	char *nbr;
	nbr = ft_itoa(n);
	ft_putstr(nbr,ret);
	free(nbr);
}

void ft_unsgndnbr(int num,int *ret)
{
	unsigned int nbr = num;
	if (nbr < 10)
		ft_putchar(nbr + '0',ret);
	else
		{
			ft_unsgndnbr(nbr / 10,ret);
			ft_unsgndnbr(nbr % 10,ret);
		}
}