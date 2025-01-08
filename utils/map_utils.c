#include "../so_long.h"

int get_map_lines(char *map_path)
{
	char *line;
	int fd;
	int y;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
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

void check_map_walls(char *map_path, t_game *game)
{
	char *line;
	int fd;
	int y;
	int size;

	printf(RED "Map Lines are: %d\n" RESET, get_map_lines(map_path));
	game->map = malloc(sizeof(char *) * get_map_lines(map_path));
	if (!game->map)
		return ;
	y = 0;
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		size = ft_strlen(line);
		// printf(GREEN "Line: %s" RESET, line);
		if (line[size - 1] == '\n')
			size--;
		game->map[y] = ft_substr(line, 0, size);
		y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void get_map(char *map_path, t_game *game)
{
	char *line;
	int size;
	int fd;
	int y;

	game->map_h = get_map_lines(map_path);
	game->map = malloc(sizeof(char *) * game->map_h);
	if (!game->map)
		return ;
	y = 0;
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		size = ft_strlen(line);
		if (line[size - 1] == '\n')
			size--;
		game->map[y] = ft_substr(line, 0, size);
		y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

// void draw_map(void *mlx_ptr, void *mlx_win, t_game *game)
// {
// 	char *line;
// 	int fd;
// 	int x;
// 	int y;

// 	int blockSize = BLOCK_SIZE;
// 	void *wall = mlx_xpm_file_to_image(mlx_ptr, "./assets/images/wall.xpm", &blockSize, &blockSize);
// 	void *bg = mlx_xpm_file_to_image(mlx_ptr, "./assets/images/brick.xpm", &blockSize, &blockSize);
// 	void *exit = mlx_xpm_file_to_image(mlx_ptr, "./assets/images/exit.xpm", &blockSize, &blockSize);
// 	void *collectible = mlx_xpm_file_to_image(mlx_ptr, "./assets/images/olive-bottle.xpm", &blockSize, &blockSize);
// 	// void *collectible = mlx_xpm_file_to_image(mlx_ptr, "./assets/images/test.xpm", &blockSize, &blockSize);
// 	void *player = mlx_xpm_file_to_image(mlx_ptr, "./assets/images/player/idle-1.xpm", &blockSize, &blockSize);

// 	// game->player_y = 0;

// 	fd = open("./assets/maps/map.ber", O_RDONLY);
// 	line = get_next_line(fd);
// 	y = 0;
// 	while (line)
// 	{
// 		printf("%s", line);
// 		x = 0;
// 		while (line[x])
// 		{
// 			if (line[x] == '1')
// 				mlx_put_image_to_window(mlx_ptr, mlx_win, wall, blockSize * x, blockSize * y);
// 			else if (line[x] == 'E')
// 				mlx_put_image_to_window(mlx_ptr, mlx_win, exit, blockSize * x, blockSize * y);
// 			else if (line[x] == 'P')
// 			{
// 				mlx_put_image_to_window(mlx_ptr, mlx_win, bg, blockSize * x, blockSize * y);
// 				mlx_put_image_to_window(mlx_ptr, mlx_win, player, blockSize * x, blockSize * y);
// 			}
// 			else if (line[x] == 'C')
// 			{
// 				mlx_put_image_to_window(mlx_ptr, mlx_win, bg, blockSize * x, blockSize * y);
// 				mlx_put_image_to_window(mlx_ptr, mlx_win, collectible, blockSize * x, blockSize * y);
// 			}
// 			else if (line[x] == '0')
// 				mlx_put_image_to_window(mlx_ptr, mlx_win, bg, blockSize * x, blockSize * y);
// 			x++;
// 		}
// 		y++;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// }

// int get_map_width()
// {
// 	char *line;
// 	int i;
// 	int fd;

// 	fd = open("./assets/maps/map.ber", O_RDONLY);
// 	line = get_next_line(fd);
// 	i = 0;
// 	while (line[i] && line[i] != '\n')
// 		i++;
// 	free(line);
// 	close(fd);
// 	return (i);
// }

// int get_map_height()
// {
// 	char *line;
// 	int map_h;
// 	int fd;

// 	fd = open("./assets/maps/map.ber", O_RDONLY);
// 	line = get_next_line(fd);
// 	map_h = 0;
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		map_h++;
// 	}
// 	free(line);
// 	close(fd);
// 	return (map_h);
// }
