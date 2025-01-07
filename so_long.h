#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "./lib/get_next_line/get_next_line.h"
# define BLOCK_SIZE 50

typedef struct s_player
{
	int player_x;
	int player_y;
	int animation_frame;
} t_player;

typedef struct s_game
{
	void *mlx_ptr;
	void *mlx_win;
	int win_h;
	int win_w;
	char **map;
	t_player player;
} t_game;

void draw_map(void *mlx_ptr, void *mlx_win, t_game *game);
int get_map_width();
int get_map_height();

#endif