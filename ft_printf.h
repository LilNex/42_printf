/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:05:25 by ichaiq            #+#    #+#             */
/*   Updated: 2022/11/15 16:10:41 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

# define UPHEX "0123456789ABCDEF"
# define LOWHEX "0123456789abcdef"
# define DEC "0123456789"

void	ft_putstr(char *s, int *len, int *i);
void	ft_putchar(char c, int *len, int *i);
int		ft_printchar(void *c, int *len);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s1);
void	ft_putnbr_base2(long nbr, char *base, int *len, int i);
void	ft_putunbr_base2(unsigned long nbr, char *base, int *len, int i);
int		ft_printf(const char *str, ...);

#endif