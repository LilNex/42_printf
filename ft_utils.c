/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:05:25 by ichaiq            #+#    #+#             */
/*   Updated: 2022/11/15 15:10:41 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putstr(char *s, int *len, int *i)
{
	size_t	l;
	int		d;

	d = 0;
	if (!s)
	{
		s = ft_strdup("(null)");
		d = 1;
	}
	l = ft_strlen(s);
	write(1, s, l);
	*len += l;
	if (i)
		*i += 2;
	if (d == 1)
		free(s);
}

void	ft_putchar(char c, int *len, int *i)
{
	write(1, &c, 1);
	if (len)
		(*len)++;
	*i += 2;
}

int	handle_cases(long *nbr, int *len)
{
	if (*nbr == LONG_MIN)
	{
		ft_printf("8000000000000000");
		*len += ft_strlen("8000000000000000");
		return (0);
	}
	return (1);
}

void	ft_putnbr_base2(long nbr, char *base, int *len, int i)
{
	int		lbase;

	(void)i;
	if (!handle_cases(&nbr, len))
		return ;
	if (!base)
		base = LOWHEX;
	lbase = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= (-1);
		ft_printchar("-", len);
	}
	if (nbr >= lbase)
	{
		ft_putnbr_base2(nbr / lbase, base, len, i);
		ft_printchar(&(base[nbr % lbase]), len);
	}
	else
		ft_printchar(&(base[nbr % lbase]), len);
}

void	ft_putunbr_base2(unsigned long nbr, char *base, int *len, int i)
{
	int		lbase;

	(void)i;
	if (!base)
		base = LOWHEX;
	lbase = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= (-1);
		ft_printchar("-", len);
	}
	if (nbr >= (unsigned long) lbase)
	{
		ft_putnbr_base2(nbr / lbase, base, len, i);
		ft_printchar(&(base[nbr % lbase]), len);
	}
	else
		ft_printchar(&(base[nbr % lbase]), len);
}
