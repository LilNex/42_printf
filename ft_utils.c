#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(char *)(s++) = 0;
}

void	ft_putstr(char *s,int *len,int *i)
{
	size_t	l;
	int d;

	d = 0;
	if (!s)
	{
		s = ft_strdup("(null)");
		d = 1;
	}
	l = ft_strlen(s);
	write(1,s,l);
	*len += l;
	if(i)
		*i += 2;
	if (d == 1)
		free(s);

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
