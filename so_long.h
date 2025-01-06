#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "./lib/get_next_line/get_next_line.h"
# define BLOCK_SIZE 50

void draw_map(void	*mlx_ptr, void	*mlx_win);
int get_map_width();
int get_map_height();

#endif