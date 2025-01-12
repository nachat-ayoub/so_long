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
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

typedef struct	s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct	s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_wall;
	void	*img_bg;
	void	*img_player;
	void	*img_exit;
	void	*img_collect;
	char	**map;
	int		b_size;
	int		map_h;
	int		map_w;
	int		win_h;
	int		win_w;
	int		player_x;
	int		player_y;
	int		collects;
	int		movements;
}	t_game;

char	**get_map(char *map_path, t_game *game);
int		is_rectangular(t_game *game);
int		is_map_valid(t_game *game);
int		has_valid_walls(t_game *game);
int		has_required_elements(t_game *game);
int		has_valid_characters(t_game *game);
int		is_path_valid(t_game *game);
void    free_map(char **map, int size);
void	count_map_elms(t_game *game, int *e, int *p, int *c);
int		count_char(char *str, char c);

#endif