# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 13:09:47 by anachat           #+#    #+#              #
#    Updated: 2025/01/19 11:00:16 by anachat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
NAME_BONUS=so_long_bonus

LIBFT_DIR=./lib/libft
PRINTF_DIR=./lib/ft_printf
GNL_DIR=./lib/get_next_line

LIBFT_LIB=$(LIBFT_DIR)/libft.a
PRINTF_LIB=$(PRINTF_DIR)/libftprintf.a

# Mandatory sources and headers
SRCS_MANDATORY=$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c \
                $(wildcard ./mandatory/utils/*.c) ./mandatory/so_long.c
OBJS_MANDATORY=$(SRCS_MANDATORY:.c=.o)

# Bonus sources and headers
SRCS_BONUS=$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c \
            $(wildcard ./bonus/utils/*_bonus.c) ./bonus/so_long_bonus.c
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

CFLAGS=-Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(PRINTF_DIR)
CC=cc

all: $(NAME)

bonus: $(NAME_BONUS)

# Rule for mandatory build
$(NAME): $(LIBFT_LIB) $(PRINTF_LIB) $(OBJS_MANDATORY)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME)

# Rule for bonus build
$(NAME_BONUS): $(LIBFT_LIB) $(PRINTF_LIB) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME_BONUS)

# Rule for mandatory object files
mandatory/%.o: mandatory/%.c mandatory/so_long.h
	$(CC) $(CFLAGS) -Imlx -Ilib -c $< -o $@

# Rule for bonus object files
bonus/%_bonus.o: bonus/%_bonus.c bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -Imlx -Ilib -c $< -o $@

# Rule to build libraries
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -rf $(OBJS_MANDATORY) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all
