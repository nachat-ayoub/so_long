/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:26:35 by anachat           #+#    #+#             */
/*   Updated: 2025/01/18 12:06:56 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_map_lines(char *map_path)
{
	char	*line;
	int		fd;
	int		y;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (0);
	y = 0;
	while (line != NULL)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (y);
}

static char	**read_map(char *map_path, char **map)
{
	char	*line;
	int		size;
	int		fd;
	int		y;

	y = 0;
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		size = ft_strlen(line);
		if (line[size - 1] == '\n')
			size--;
		map[y] = ft_substr(line, 0, size);
		free(line);
		if (!map[y])
			return (close(fd), free_map(map, y), NULL);
		line = get_next_line(fd);
		y++;
	}
	return (close(fd), map);
}

char	**get_map(char *map_path, t_game *game)
{
	char	**map;

	map = NULL;
	game->map_h = get_map_lines(map_path);
	if (game->map_h == -1)
		return (handle_error("Failed to open map file", game), NULL);
	if (game->map_h == 0)
		return (handle_error("Map is empty", game), NULL);
	map = malloc(sizeof(char *) * (game->map_h));
	if (!map)
		return (handle_error("Allocation error", game), NULL);
	return (read_map(map_path, map));
}
