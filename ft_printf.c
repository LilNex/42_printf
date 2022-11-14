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

#include <stddef.h>
#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

void	ft_format(const char *str, va_list arg, int *len, int *i)
{
	int	x;

	if (str[*i + 1] == '%')
		ft_putchar('%', len, i);
	else if (str[*i + 1] == 'c')
		ft_putchar(va_arg(arg, int), len, i);
	else if (str[*i + 1] == 's')
		ft_putstr(va_arg(arg, void *), len, i);
	else if (str[*i + 1] == 'p')
	{
		ft_putstr("0x", len, 0);
		ft_putnbr_base2(va_arg(arg, long), 16, len, *i = *i + 2, 'x');
	}
	else if (str[*i + 1] == 'u')
		ft_putnbr_base2((unsigned long)va_arg(arg, unsigned long), 10,
			len, *i = *i + 2, 'l');
	else if (str[*i + 1] == 'i' || str[*i + 1] == 'd')
		ft_putnbr_base2(va_arg(arg, int), 10, len, *i = *i + 2, 'x');
	else if (str[*i + 1] == 'X' || str[*i + 1] == 'x')
	{
		x = (int)str[*i + 1];
		ft_putnbr_base2(va_arg(arg, unsigned int), 16,
			len, (*i = *i + 2), x);
	}
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

// int main()
// {
// 	// char s[]="hel%%lo %s world\n";
// 	// char c[]="zbi";
// 	// char car = 'z';
// 	// int len = ft_printf(s,c);
// 	// int le = printf(s,c);
// 	// printf("----------------------\n");
// 	// printf("len : %d",len);
// 	// printf("le : %d",le);
// 	// printf(s,c);
// 	char *s = ft_strdup("adress :%d\n");
// 	char *p = ft_strdup("test test");
// 	// double x = 48484;
// 	int len = ft_printf("\nthis %X number\naa", (unsigned int)p);
// 	int len2 = printf("\nthis %X num% ber\naa", (unsigned int)p);
// 	printf("\nlen : %d | len2 : %d",len,len2);

// }
