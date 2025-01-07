# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 13:09:47 by anachat           #+#    #+#              #
#    Updated: 2025/01/07 15:49:52 by anachat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
LIBFT_DIR =./lib/libft
PRINTF_DIR =./lib/ft_printf
GNL_DIR =./lib/get_next_line

LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

SRCS=$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c map_utils.c main.c
OBJS=$(SRCS:.c=.o)
CFLAGS=-Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(PRINTF_DIR)
CC=cc

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(PRINTF_LIB) $(OBJS)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME)
# $(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -Imlx -Ilib -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all
