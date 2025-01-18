/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:51:01 by anachat           #+#    #+#             */
/*   Updated: 2025/01/18 16:17:19 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_arg(char *file_name)
{
	char	*ext;

	ext = file_name + (ft_strlen(file_name) - 4);
	if (ft_strncmp(ext, ".ber", 5) != 0)
		return (handle_error("Invalid map file extension", NULL), 0);
	return (1);
}

void	init_struct(t_game *g)
{
	g->coins = 0;
	g->mlx = NULL;
	g->win = NULL;
	g->map = NULL;
	g->img_bg = NULL;
	g->img_coins = NULL;
	g->img_exit = NULL;
	g->img_pl = NULL;
	g->img_wall = NULL;
}

static void	setup_game(char *map_path, t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
	{
		handle_error("Allocation error", *game);
		return ;
	}
	init_struct(*game);
	(*game)->map = get_map(map_path, *game);
	if (!(*game)->map)
	{
		handle_error("Allocation error", *game);
		return ;
	}
	(*game)->map_w = ft_strlen((*game)->map[0]);
	is_map_valid(*game);
	init_game(*game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2 || !is_valid_arg(argv[1]))
		handle_error("Invalid map arg", game);
	setup_game(argv[1], &game);
	draw_map(game);
	mlx_hook(game->win, 17, 0, handle_close, game);
	mlx_key_hook(game->win, handle_input, game);
	mlx_loop(game->mlx);
	return (0);
}
