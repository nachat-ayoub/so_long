# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 16:39:34 by anachat           #+#    #+#              #
#    Updated: 2024/11/20 16:40:59 by anachat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CFILES=ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_adrs.c ft_putnbr_hex.c ft_putnbr_uns.c ft_putstr.c
OBJECTS=$(CFILES:.c=.o)
CC=cc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
