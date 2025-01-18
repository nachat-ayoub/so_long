/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:39:56 by anachat           #+#    #+#             */
/*   Updated: 2025/01/18 15:57:27 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_player(int key, t_game *g)
{
	int	x;
	int	y;

	x = g->pl_x;
	y = g->pl_y;
	if (key == KEY_ESC)
		exit_game(g);
	else if (key == KEY_UP)
		y -= 1;
	else if (key == KEY_DOWN)
		y += 1;
	else if (key == KEY_LEFT)
		x -= 1;
	else if (key == KEY_RIGHT)
		x += 1;
	if (g->map[y][x] != '1')
	{
		if (g->pl_x != x || g->pl_y != y)
		{
			g->moves++;
			ft_printf("player moves: %d\n", g->moves);
			g->pl_x = x;
			g->pl_y = y;
		}
	}
}

int	handle_input(int key, t_game *game)
{
	move_player(key, game);
	if (game->map[game->pl_y][game->pl_x] == 'C')
	{
		game->coins--;
		game->map[game->pl_y][game->pl_x] = '0';
	}
	else if (game->map[game->pl_y][game->pl_x] == 'E')
	{
		if (game->coins == 0)
			exit_game(game);
	}
	draw_map(game);
	return (0);
}
