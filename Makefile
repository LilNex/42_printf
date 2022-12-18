# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2022/11/13 15:46:25 by ichaiq            #+#    #+#             #
#   Updated: 2022/11/15 23:31:41 by ichaiq           ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = libftprintf.a
HDRS = ft_printf.h
SOURCES = \
	ft_printf.c ft_utils.c ft_utils2.c \

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

bonus: $(OBJECTS) $(BOBJECTS)
	$(AR) -r $(NAME) $?

%.o: %.c $(HDRS)
	$(CC) -c  $(CFLAGS) $<

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all bonus

.PHONY: all bonus clean fclean re