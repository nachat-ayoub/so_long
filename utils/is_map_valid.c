/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:00:30 by anachat           #+#    #+#             */
/*   Updated: 2025/01/12 16:07:56 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_map_valid(t_game *game)
{
	int	res;

	res = 1;
	if (is_rectangular(game) != 1)
	{
		res = -1;
		ft_printf(MAGENTA "[MAP] map is not rectangular\n" RESET);
	}
	else if (has_valid_walls(game) != 1)
	{
		res = -2;
		ft_printf(MAGENTA "[MAP] map does not have walls on sides\n" RESET);
	}
	else if (has_required_chars(game) != 1)
	{
		res = -3;
		ft_printf(MAGENTA "[MAP] map does not have correct elements\n" RESET);
	}
	else if (has_valid_chas(game) != 1)
	{
		res = -4;
		ft_printf(MAGENTA "[MAP] map has invalid characters\n" RESET);
	}
	else if (is_path_valid(game) != 1)
	{
		res = -5;
		ft_printf(MAGENTA "[MAP] map has invalid path\n" RESET);
	}
	return (res);
}

int	is_rectangular(t_game *game)
{
	int	map_w;
	int	i;

	i = 0;
	map_w = ft_strlen(game->map[i]);
	while (i < game->map_h)
	{
		if (map_w != game->map_w)
			return (-1);
		i++;
	}
	return (1);
}

int	has_valid_walls(t_game *game)
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

int	has_required_chars(t_game *game)
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

int	has_valid_chas(t_game *game)
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
