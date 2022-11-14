


#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdio.h>
# include <unistd.h>

void	ft_putstr(char *s, int *len, int *i);
void	ft_putchar(char c, int *len, int *i);
int		ft_printchar(void *c, int *len);
// void	ft_putnbr_base(int nbr, int base);
// void	ft_putnbr_base(int nbr, int base, int *len, int i, char c);
void	ft_putnbr_base2(long nbr, int base, int *len, int i, int c);
void	ft_putadrr_base(unsigned long nbr, int base, int *len, int i, char c);

#endif