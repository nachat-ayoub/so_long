/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:51:01 by anachat           #+#    #+#             */
/*   Updated: 2025/01/16 12:50:06 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_arg(char *arg)
{
	if (ft_strncmp(ft_strrchr(arg, '.'), ".ber", 5) != 0)
		return (0);
	return (1);
}

static int	setup_game(char *map_path, t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (1);
	(*game)->coins = 0;
	(*game)->map = get_map(map_path, *game);
	if (!(*game)->map)
		return (1);
	(*game)->map_w = ft_strlen((*game)->map[0]);
	is_map_valid(*game);
	if (init_game(*game))
	{
		perror("Error\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2 || !is_valid_arg(argv[1]))
	{
		handle_error("invalid map arg", NULL, 0);
		return (1);
	}
	if (setup_game(argv[1], &game))
		return (1);
	draw_map(game);
	mlx_hook(game->win, 17, 0, handle_close, game);
	mlx_key_hook(game->win, handle_input, game);
	mlx_loop(game->mlx);
	return (0);
}
