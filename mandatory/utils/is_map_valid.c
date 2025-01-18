/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:00:30 by anachat           #+#    #+#             */
/*   Updated: 2025/01/18 15:21:09 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_rectangular(t_game *game)
{
	int	map_w;
	int	i;

	i = 0;
	while (i < game->map_h)
	{
		map_w = ft_strlen(game->map[i]);
		if (map_w != game->map_w)
			return (-1);
		i++;
	}
	return (1);
}

static int	has_valid_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map && i < game->map_h)
	{
		if (game->map[i][0] != '1')
			return (-1);
		if (game->map[i][game->map_w - 1] != '1')
			return (-1);
		if (i == 0 || i == game->map_h - 1)
		{
			j = 0;
			while (game->map[i][j])
			{
				if (game->map[i][j] != '1')
					return (-1);
				j++;
			}
		}
		i++;
	}
	return (1);
}

static int	has_required_chars(t_game *game)
{
	int	e;
	int	p;
	int	c;

	e = 0;
	p = 0;
	c = 0;
	count_map_elms(game, &e, &p, &c);
	if (e != 1 || p != 1 || c < 1)
		return (-1);
	return (1);
}

static int	has_valid_chars(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (game->map && ++i < game->map_h)
	{
		j = -1;
		while (game->map[i][++j])
		{
			c = game->map[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (-1);
		}
	}
	return (1);
}

int	is_map_valid(t_game *g)
{
	if (is_rectangular(g) != 1)
		return (handle_error("Map is not rectangular", g), 0);
	else if (has_valid_walls(g) != 1)
		return (handle_error("Map does not have walls on borders", g), 0);
	else if (has_required_chars(g) != 1)
		return (handle_error("Map does not have required chars", g), 0);
	else if (has_valid_chars(g) != 1)
		return (handle_error("Map has invalid chars", g), 0);
	else if (is_path_valid(g) != 1)
		return (handle_error("Map has invalid path", g), 0);
	return (1);
}
