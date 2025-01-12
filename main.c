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
	g->movements = 0;
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
void exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	free(game->map);
	free(game->mlx_ptr);
	free(game);
	exit(0);
}

int handle_close(t_game *game)
{
	exit_game(game);
	return (0);
}

int	handle_input(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (key == 53)
		exit_game(game);
	if (key == 13)
		y -= 1;
	else if (key == 1)
		y += 1;
	else if (key == 0)
		x -= 1;
	else if (key == 2)
		x += 1;
	if (game->map[y][x] != '1')
	{
		if (game->player_x != x || game->player_y != y)
		{
			game->movements++;
			ft_printf("player moves: %d\n", game->movements);
		}
		game->player_x = x;
		game->player_y = y;
	}
	if (game->map[y][x] == 'C')
	{
		if (game->collects != 0)
			game->collects--;
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == 'E')
	{
		if (game->collects == 0)
			exit_game(game);
	}
	draw_map(game);
	return (0);
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
		mlx_hook(game->mlx_win, 17, 0, handle_close, game);
		mlx_key_hook(game->mlx_win, handle_input, game);
		mlx_loop(game->mlx_ptr);
		return (0);
	}
	perror("Error\n");
	return (1);
}
