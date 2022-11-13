#include "libft.h"
void	ft_putstr(char *s,int *len,int *i)
{
	size_t	l;

	if (!s)
		return ;
	l = ft_strlen(s);
	write(1,s,l);
    *len += l;
    *i += 2;

}
size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

void ft_putchar(char c, int *len,int *i)
{
    write(1,&c,1);
    (*len)++;
    *i += 2;
}
void	ft_putnbr_base(int nbr, int base)
{
	if (nbr < 0)
	{
		nbr *= (-1);
		if (!((nbr - 1) == 2147483647))
			write(1, "-", 1);
	}
	if ((nbr - 1) == 2147483647)
	{
		return ;
	}
	if (nbr >= base)
	{
		ft_putnbr_base(nbr / base, base);
		write(1, &("0123456789ABCDEF"[nbr % base]), 1);
	}
	else
	{
		write(1, &("0123456789ABCDEF"[nbr % base]), 1);
	}
}