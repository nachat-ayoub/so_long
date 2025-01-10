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

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2 || !is_valid(argv[1]))
	{
		ft_printf("\n[❌] invalid map argument");
		return (1);
	}
	ft_printf("\n[✅] 😅 valid map arg\n");
	game = malloc(sizeof(game));
	if (!game)
		return (1);
	game->map = get_map(argv[1], game);
	if (!game->map)
		return (1);
	game->map_w = ft_strlen(game->map[0]);

	printf(YELLOW "Map W: %d\n" RESET, game->map_w);
	printf(YELLOW "Map H: %d\n" RESET, game->map_h);
	int res = is_map_valid(game);
	if (res == 1)
		printf(GREEN "=========[ Valid Map: %d ]=========\n" RESET, res);
	else
		printf(RED   "=========[ Invalid Map: %d ]=========\n" RESET, res);
	return (0);
}
