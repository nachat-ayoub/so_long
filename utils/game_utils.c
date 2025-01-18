/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:19:19 by anachat           #+#    #+#             */
/*   Updated: 2025/01/18 16:44:34 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_images(t_game *g)
{
	if (g->img_bg)
		mlx_destroy_image(g->mlx, g->img_bg);
	if (g->img_coins)
		mlx_destroy_image(g->mlx, g->img_coins);
	if (g->img_exit)
		mlx_destroy_image(g->mlx, g->img_exit);
	if (g->img_pl)
		mlx_destroy_image(g->mlx, g->img_pl);
	if (g->img_wall)
		mlx_destroy_image(g->mlx, g->img_wall);
}

void	exit_game(t_game *game)
{
	if (game)
	{
		if (game->map)
			free_map(game->map, game->map_h);
		if (game->mlx)
		{
			if (game->win)
				mlx_destroy_window(game->mlx, game->win);
			destroy_images(game);
			free(game->mlx);
		}
		free(game);
	}
	exit(1);
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
		return (handle_error("Failed to initialize mlx", g), 1);
	size = BLOCK_SIZE;
	win_w = g->map_w * size;
	win_h = g->map_h * size;
	g->b_size = size;
	g->img_wall = load_img(g->mlx, "./textures/wall.xpm", &size, g);
	g->img_bg = load_img(g->mlx, "./textures/brick.xpm", &size, g);
	g->img_pl = load_img(g->mlx, "./textures/player_1.xpm", &size, g);
	g->img_exit = load_img(g->mlx, "./textures/exit.xpm", &size, g);
	g->img_coins = load_img(g->mlx, "./textures/olive.xpm", &size, g);
	g->moves = 0;
	g->win = mlx_new_window(g->mlx, win_w, win_h, "so_long");
	return (0);
}
