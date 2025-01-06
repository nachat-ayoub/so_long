# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 13:09:47 by anachat           #+#    #+#              #
#    Updated: 2025/01/05 09:53:29 by anachat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CFILES=./lib/get_next_line/get_next_line.c ./lib/get_next_line/get_next_line_utils.c map_utils.c main.c
OBJECTS=$(CFILES:.c=.o)
CC=cc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -Imlx -Ilib -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
