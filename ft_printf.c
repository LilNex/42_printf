/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:19:56 by ichaiq            #+#    #+#             */
/*   Updated: 2022/11/14 12:42:48 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_format(const char *str, va_list arg, int *len, int *i)
{
	if (str[*i + 1] == '%')
		ft_putchar('%', len, i);
	else if (str[*i + 1] == 'c')
		ft_putchar(va_arg(arg, int), len, i);
	else if (str[*i + 1] == 's')
		ft_putstr(va_arg(arg, void *), len, i);
	else if (str[*i + 1] == 'p')
	{
		ft_putstr("0x", len, 0);
		ft_putunbr_base2(va_arg(arg, unsigned long),
			(LOWHEX), len, *i = *i + 2);
	}
	else if (str[*i + 1] == 'u')
		ft_putunbr_base2((unsigned int)va_arg(arg, unsigned long), DEC,
			len, *i = *i + 2);
	else if (str[*i + 1] == 'i' || str[*i + 1] == 'd')
		ft_putnbr_base2(va_arg(arg, int), DEC, len, *i = *i + 2);
	else if (str[*i + 1] == 'X' )
		ft_putnbr_base2(va_arg(arg, unsigned int), UPHEX, len, (*i = *i + 2));
	else if (str[*i + 1] == 'x')
		ft_putnbr_base2(va_arg(arg, unsigned int), LOWHEX, len, (*i = *i + 2));
	else if (str[*i + 1] == '\0')
		ft_printchar((void *)&str[*i], len);
	else
		ft_putchar(str[*i + 1], len, i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;
	int		e;

	i = 0;
	len = 0;
	e = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (len);
			ft_format(str, arg, &len, &i);
		}
		else
			if (str[i] && ft_printchar(((void *)&str[i++]), &len) == -1)
				return (-1);
	}
	return (len);
}
