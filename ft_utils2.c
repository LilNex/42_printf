/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:25:11 by ichaiq            #+#    #+#             */
/*   Updated: 2022/11/15 15:15:41 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(char *)(s++) = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	if (count == 0 || size == 0)
	{
		count = 1;
		size = count;
	}
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return ((void *)ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		len;

	len = ft_strlen((const char *)s1);
	new = ft_calloc((len + 1), sizeof(char));
	if (!new)
		return (NULL);
	if (len == 0)
	{
		*new = '\0';
		return (new);
	}
	while (*s1)
		*new++ = *s1++;
	*new = '\0';
	return (new - len);
}	

int	ft_printchar(void *c, int *len)
{
	if (write(1, c, 1) == -1)
		return (-1);
	(*len)++;
	return (1);
}
