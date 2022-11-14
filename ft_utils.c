#include "libft.h"
void	ft_putstr(char *s,int *len,int *i)
{
	size_t	l;

	if (!s)
		return ;
	l = ft_strlen(s);
	write(1,s,l);
	*len += l;
	if(i)
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
	write(1, &c, 1);
	if(len)
		(*len)++;
	*i += 2;
}

void	ft_putnbr_base(int nbr, int base, int *len, int i, char c)
{
	char	set;

	(void)i;
	if (c == 'u')
		set = "0123456789ABCDEF";
	else 
		set = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr *= (-1);
		(*len)++;
		write(1, "-", 1);
	}
	if ((nbr - 1) == 2147483647)
	{
		return ;
	}
	if (nbr >= base)
	{
		ft_putnbr_base(nbr / base, base,len,i,c);
		write(1, &(set[nbr % base]), 1);
		(*len)++;
	}
	else
	{
		write(1, &(set[nbr % base]), 1);
		(*len)++;
	}
}
void	ft_putnbr_base2(long nbr, int base, int *len, int i, char c)
{
	// (void)i;
	char *set;

	if (c == 'u')
		set = "0123456789ABCDEF";
	else 
		set = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr *= (-1);
		// if (!((nbr - 1) == 2147483647))
		write(1, "-", 1);
	}
	if ((nbr - 1) == 2147483647)
	{
		return ;
	}
	if (nbr >= base)
	{
		ft_putnbr_base(nbr / base, base,len,i,c);
		write(1, &(set[nbr % base]), 1);
		(*len)++;
	}
	else
	{
		write(1, &(set[nbr % base]), 1);
		(*len)++;
	}
}

void	ft_putadrr_base(unsigned long nbr, int base, int *len, int i, char c)
{
	// (void)i;
	char *set;

	if (c == 'u')
		set = "0123456789ABCDEF";
	else 
		set = "0123456789abcdef";

	if (nbr >= (unsigned long)base)
	{
		ft_putadrr_base(nbr / base, base, len, i, c);
		write(1, &(set[nbr % base]), 1);
		(*len)++;
	}
	else
	{
		write(1, &(set[nbr % base]), 1);
		(*len)++;
	}
}