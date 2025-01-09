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

typedef struct	s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	size_t	map_h;
	size_t	map_w;
	size_t	win_h;
	size_t	win_w;
	int		player_x;
	int		player_y;
	int		player_frame;
}	t_game;

void 	get_map(char *map_path, t_game *game);
int		is_rectangular(t_game *game);
int		is_map_valid(t_game *game);
int		has_valid_walls(t_game *game);
int		has_required_elements(t_game *game);
int		has_valid_characters(t_game *game);
int		is_path_valid(t_game *game);
void    free_map(t_game *game);
void	count_map_elms(t_game *game, int *e, int *p, int *c);

#endif