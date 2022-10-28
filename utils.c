#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(const char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char *nbr;
	nbr = ft_itoa(n);
	ft_putstr(nbr);
	free(nbr);
}

void ft_unsgndnbr(int num)
{
	unsigned int nbr = num;
	if (nbr < 10)
		ft_putchar(nbr + '0');
	else
		{
			ft_unsgndnbr(nbr / 10);
			ft_unsgndnbr(nbr % 10);
		}
}