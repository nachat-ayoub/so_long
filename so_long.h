#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "./lib/get_next_line/get_next_line.h"
# include "./lib/ft_printf/ft_printf.h"
# include "./lib/libft/libft.h"
# define BLOCK_SIZE 50
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

typedef struct s_game
{
	void *mlx_ptr;
	void *mlx_win;
	int win_h;
	int win_w;
	char **map;
	int player_x;
	int player_y;
	int player_frame;
} t_game;

void get_map(char *map_path, t_game *game);

// void draw_map(void *mlx_ptr, void *mlx_win, t_game *game);
// int get_map_width();
// int get_map_height();

#endif