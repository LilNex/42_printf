#include <stddef.h>
#include <stdarg.h>
// #include "libft.h"
#include "libftprintf.h"

int ft_printf(const char *str,...)
{
    int i;
    va_list arg;
    char *s;
    int len;
    int e;

    i = 0;
    len = 0;
    e = 0;
    va_start(arg,str);
    while (str[i])
    {
        if(str[i] == '%')
        {
            if (str[i+1] == '%')
                ft_putchar('%',&len,&i);
            else if (str[i + 1] == 's')
                ft_putstr(va_arg(arg,void *),&len,&i);
            else if (str[i + 1] == 'c')
                ft_putchar(va_arg(arg,int),&len,&i);
            else if(str[i + 1] == 'X')
                ft_putnbr_base(ft)
        }
        e = write(1,&str[i++],1);
        len++;
        if (e == -1)
            return -1;
    }
    return len;
    
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

    printf("%x",1000);

}
