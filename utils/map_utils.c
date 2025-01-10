#include "../so_long.h"

int get_map_lines(char *map_path)
{
	char *line;
	int fd;
	int y;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	y = 0;
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (y);
}

char **get_map(char *map_path, t_game *game)
{
	char **map;
	char *line;
	int size;
	int fd;
	int y;

	game->map_h = get_map_lines(map_path);
	map = malloc(sizeof(char *) * game->map_h);
	if (!map)
		return (NULL);
	y = 0;
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		size = ft_strlen(line);
		if (line[size - 1] == '\n')
			size--;
		map[y] = ft_substr(line, 0, size);
		if (!map[y])
			return (close(fd), free_map(map, y), NULL);
		y++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), map);
}
