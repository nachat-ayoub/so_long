/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:58:53 by anachat           #+#    #+#             */
/*   Updated: 2025/01/18 16:56:12 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"

# define BLOCK_SIZE 50
# define KEY_ESC 53
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2

# define RED     "\033[31m"
# define RESET   "\033[0m"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_bg;
	void	*img_pl;
	void	*img_exit;
	void	*img_coins;
	char	**map;
	int		b_size;
	int		map_h;
	int		map_w;
	int		win_h;
	int		win_w;
	int		pl_x;
	int		pl_y;
	int		coins;
	int		moves;
}	t_game;

char	**get_map(char *map_path, t_game *game);
int		is_map_valid(t_game *game);
int		is_path_valid(t_game *game);
void	free_map(char **map, int size);
void	count_map_elms(t_game *game, int *e, int *p, int *c);
int		count_char(char *str, char c);
int		handle_input(int key, t_game *game);
int		handle_close(t_game *game);
void	exit_game(t_game *game);
int		init_game(t_game *g);
void	draw_map(t_game *g);
void	*load_img(void *mlx, char *img, int *size, t_game *g);
void	*get_img(t_game *g, int y, int x);
int		put_img(t_game *g, void *img, int x, int y);
int		handle_error(char *msg, t_game *g);

#endif