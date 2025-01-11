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

void	*load_img(void *mlx, char *img_path, int *size)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(mlx, img_path, size, size);
	return (ptr);
}

int	init_game(t_game *g)
{
	int		size;

	g->mlx_ptr = mlx_init();
	if (!(g->mlx_ptr))
		return (1);
	g->mlx_win = mlx_new_window(g->mlx_ptr, g->map_w * BLOCK_SIZE, g->map_h * BLOCK_SIZE, "so_long");
	size = BLOCK_SIZE;
	g->b_size = size;
	g->img_wall = load_img(g->mlx_ptr, "./assets/wall.xpm", &size);
	g->img_bg = load_img(g->mlx_ptr, "./assets/brick.xpm", &size);
	g->img_player = load_img(g->mlx_ptr, "./assets/player/1.xpm", &size);
	g->img_exit = load_img(g->mlx_ptr, "./assets/exit.xpm", &size);
	g->img_collect = load_img(g->mlx_ptr, "./assets/test.xpm", &size);
	return (0);
}

void	*get_img(t_game *g, int y, int x)
{
	void	*img;
	char	c;

	img = NULL;
	c = g->map[y][x];
	if (c == '1')
		img = g->img_wall;
	else if (c == 'E')
		img = g->img_exit;
	else if (c == 'C')
	{
		mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->img_bg, g->b_size * x, g->b_size * y);
		img = g->img_collect;
	}
	else
		img = g->img_bg;
	return (img);
}

void draw_map(t_game *g)
{
	void	*img;
	int		i;
	int		j;

	i = 0;
	while (i < g->map_h)
	{
		j = 0;
		while (g->map[i][j])
		{
			img = get_img(g, i, j);
			if (img)
				mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, img, g->b_size * j, g->b_size * i);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->img_player, g->b_size * g->player_x, g->b_size * g->player_y);
}

int main(int argc, char **argv)
{
	t_game	*game;
	int		err;

	if (argc == 2 && is_valid(argv[1]))
	{
		game = malloc(sizeof(t_game));
		if (!game)
			return (1);
		game->collects = 0;
		game->map = get_map(argv[1], game);
		if (!game->map)
			return (1);
		game->map_w = ft_strlen(game->map[0]);
		int res = is_map_valid(game);
		if (res != 1)
		{
			perror("Error\n");
			return (1);
		}
		err = init_game(game);
		if (err)
		{
			perror("Error\n");
			return (1);
		}
		draw_map(game);
		printf("Map Collectibles are: %d\n\n", game->collects);
		mlx_loop(game->mlx_ptr);
		return (0);
	}
	perror("Error\n");
	return (1);
}
