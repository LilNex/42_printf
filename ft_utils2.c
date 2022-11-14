# include "libftprintf.h"
# include "libft.h"

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

void	ft_putnbr_base2(long nbr, int base, int *len, int i, int c)
{
	char	*set;

	(void)i;
	if (c == 'X')
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr *= (-1);
		ft_printchar("-", len);
	}
	if (nbr >= base)
	{
		ft_putnbr_base2(nbr / base, base, len, i, c);
		ft_printchar(&(set[nbr % base]), len);
	}
	else
		ft_printchar(&(set[nbr % base]), len);
}
