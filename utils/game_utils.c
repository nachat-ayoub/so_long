/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:19:19 by anachat           #+#    #+#             */
/*   Updated: 2025/01/12 15:55:49 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	free(game->mlx);
	free(game);
	exit(0);
}

int	handle_close(t_game *game)
{
	exit_game(game);
	return (0);
}

int	init_game(t_game *g)
{
	int		size;
	int		win_w;
	int		win_h;

	g->mlx = mlx_init();
	if (!(g->mlx))
		return (1);
	size = BLOCK_SIZE;
	win_w = g->map_w * size;
	win_h = g->map_h * size;
	g->win = mlx_new_window(g->mlx, win_w, win_h, "so_long");
	g->b_size = size;
	g->img_wall = load_img(g->mlx, "./assets/wall.xpm", &size);
	g->img_bg = load_img(g->mlx, "./assets/brick.xpm", &size);
	g->img_pl = load_img(g->mlx, "./assets/player/1.xpm", &size);
	g->img_exit = load_img(g->mlx, "./assets/exit.xpm", &size);
	g->img_coins = load_img(g->mlx, "./assets/test.xpm", &size);
	g->moves = 0;
	return (0);
}
