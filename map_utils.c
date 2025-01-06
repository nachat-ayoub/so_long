#include "so_long.h"

void draw_map(void	*mlx_ptr, void	*mlx_win)
{
	char	*line;
	int		fd;
	int		x;
	int		y;

	int blockSize = BLOCK_SIZE;
	void *wall = mlx_xpm_file_to_image(mlx_ptr, "./assets/images/wall.xpm", &blockSize, &blockSize);
	void *bg = mlx_xpm_file_to_image(mlx_ptr, "./assets/images/brick.xpm", &blockSize, &blockSize);
	void *exit = mlx_xpm_file_to_image(mlx_ptr, "./assets/images/exit.xpm", &blockSize, &blockSize);
	// void *collectible = mlx_xpm_file_to_image(mlx_ptr, "./assets/images/olive-bottle.xpm", &blockSize, &blockSize);
	void *collectible = mlx_xpm_file_to_image(mlx_ptr, "./assets/images/test.xpm", &blockSize, &blockSize);

	fd = open("./assets/maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
	y = 0;
    while (line) {
        printf("%s", line);
		x = 0;
		while (line[x])
		{
			if (line[x] == '1')
				mlx_put_image_to_window(mlx_ptr, mlx_win, wall, blockSize*x, blockSize*y);
			else if (line[x] == 'E')
				mlx_put_image_to_window(mlx_ptr, mlx_win, exit, blockSize*x, blockSize*y);
			else if (line[x] == 'C')
			{
				mlx_put_image_to_window(mlx_ptr, mlx_win, bg, blockSize*x, blockSize*y);
				mlx_put_image_to_window(mlx_ptr, mlx_win, collectible, blockSize*x, blockSize*y);
			}
			else if (line[x] == '0')
				mlx_put_image_to_window(mlx_ptr, mlx_win, bg, blockSize*x, blockSize*y);
			x++;
		}
		y++;
        free(line);
		line = get_next_line(fd);
    }
    close(fd);
}

int get_map_width()
{
	char	*line;
	int		i;
	int		fd;

	fd = open("./assets/maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	free(line);
    close(fd);
	return (i);
}

int get_map_height()
{
	char	*line;
	int		map_h;
	int		fd;

	fd = open("./assets/maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
	map_h = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map_h++;
	}
	free(line);
    close(fd);
	return (map_h);
}