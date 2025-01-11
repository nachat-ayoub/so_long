#include "so_long.h"

int is_valid(char *path)
{
	int		fd;
	char	*line;

	if (ft_strncmp(ft_strrchr(path, '.'), ".ber", 5) != 0)
		return (0);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	close(fd);
	if (!line)
		return (0);
	return (free(line), 1);
}

void	init_game(t_game *game)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	game->mlx_ptr = mlx;
	win = mlx_new_window(mlx, game->map_w * BLOCK_SIZE, game->map_h * BLOCK_SIZE, "so_long");
	game->mlx_win = win;
}

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2 && is_valid(argv[1]))
	{
		game = malloc(sizeof(game));
		if (!game)
			return (1);
		game->map = get_map(argv[1], game);
		if (!game->map)
			return (1);
		game->map_w = ft_strlen(game->map[0]);
		int res = is_map_valid(game);
		if (res != 1)
		{
			perror("Error\nInvalide map");
		}
	}
	perror("Error\nInvalide map arg");
	return (0);
}
