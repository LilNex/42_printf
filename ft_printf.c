#include <stddef.h>
#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
	int     i;
	va_list arg;
	char    *s;
	int     len;
	int		e;

	i = 0;
	len = 0;
	e = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				ft_putchar('%', &len, &i);
			else if (str[i + 1] == 'c')
				ft_putchar(va_arg(arg, int), &len, &i);
			else if (str[i + 1] == 's')
				ft_putstr(va_arg(arg, void *), &len, &i);
			else if (str[i + 1] == 'p')
			{
				ft_putstr("0x",&len,0);
				ft_putadrr_base(va_arg(arg, unsigned long), 16, &len, i = i + 2, 'l');
			}
			else if (str[i + 1] == 'u')
				ft_putnbr_base(va_arg(arg,unsigned int), 10, &len, i = i + 2,'l');
			else if (str[i + 1] == 'i')
				ft_putnbr_base(va_arg(arg, int), 10, &len, i = i + 2, 'l');
			else if (str[i + 1] == 'd')
				ft_putnbr_base(va_arg(arg,long), 10, &len, i = i + 2, 'l');
			else if (str[i + 1] == 'X')
				ft_putnbr_base2(va_arg(arg, int), 16, &len, i = i + 2,'u');
			else if (str[i + 1] == 'x')
				ft_putnbr_base2(va_arg(arg, int), 16, &len, i = i + 2,'l');
			else if (str[i + 1] == 'x')
				ft_putnbr_base(va_arg(arg, int), 16, &len, i = i + 2,'l');
		
		}
		if (str[i])
		{
			e = write(1, &str[i++], 1);
			len = len + 1;
			if (e == -1)
				return (-1);
		}
	}
	return (len);
}

int main()
{
	// char s[]="hel%%lo %s world\n";
	// char c[]="zbi";
	// char car = 'z';
	// int len = ft_printf(s,c);
	// int le = printf(s,c);
	// printf("----------------------\n");
	// printf("len : %d",len);
	// printf("le : %d",le);
	// printf(s,c);
	char *s = ft_strdup("adress :%d\n");
	char *p = ft_strdup("allo allo cha3lo `&é\n cha3lo niran %");
	double x = 48484;
	int len = ft_printf(s,p);
	int len2 = printf(s,p);
	printf("\nlen : %d | len2 : %d",len,len2);

}
