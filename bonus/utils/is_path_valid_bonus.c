/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path_valid_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:37:01 by anachat           #+#    #+#             */
/*   Updated: 2025/01/19 10:53:19 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	**copy_map(t_game *game)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * game->map_h);
	if (!map)
		return (NULL);
	i = 0;
	while (i < game->map_h)
	{
		map[i] = ft_strdup(game->map[i]);
		if (!map[i])
			return (free_map(map, i), NULL);
		game->coins += count_char(map[i], 'C');
		i++;
	}
	return (map);
}

void	flood_fill(t_game *game, char **map, int y, int x)
{
	int		map_w;
	int		map_h;
	char	c;

	map_w = game->map_w;
	map_h = game->map_h;
	if (x < 0 || y < 0 || x >= map_w || y >= map_h)
		return ;
	c = map[y][x];
	if (c == 'f' || c == '1')
		return ;
	map[y][x] = 'f';
	flood_fill(game, map, y + 1, x);
	flood_fill(game, map, y - 1, x);
	flood_fill(game, map, y, x + 1);
	flood_fill(game, map, y, x - 1);
}

t_pos	*get_char_pos(t_game *game, char c)
{
	int		i;
	int		j;
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	if (!pos)
		return (NULL);
	pos->x = -1;
	pos->y = -1;
	i = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (game->map[i][j] == c)
				return (pos->y = i, pos->x = j, pos);
			j++;
		}
		i++;
	}
	return (free(pos), NULL);
}

int	is_map_filled(char **map, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != 'f' && map[i][j] != '0')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_path_valid(t_game *game)
{
	char	**tmp_map;
	t_pos	*pos;
	int		res;

	tmp_map = copy_map(game);
	if (!tmp_map)
		return (handle_error("Allocation error", game), -1);
	pos = get_char_pos(game, 'P');
	if (!pos)
	{
		free_map(tmp_map, game->map_h);
		return (handle_error("Allocation error", game), -1);
	}
	game->pl_x = pos->x;
	game->pl_y = pos->y;
	free(pos);
	flood_fill(game, tmp_map, game->pl_y, game->pl_x);
	res = is_map_filled(tmp_map, game->map_h);
	free_map(tmp_map, game->map_h);
	game->map[game->pl_y][game->pl_x] = '0';
	return (res);
}
