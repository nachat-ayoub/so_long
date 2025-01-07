#include "so_long.h"

int is_map_valid(t_game *game)
{
	int 	i;
	size_t map_width;

	map_width = ft_strlen(game->map[0]);
	i = 0;
	while (game->map && i < 9)
	{ 
		printf(BLUE "Line: %s\n" RESET, game->map[i]);
		if (ft_strlen(game->map[i]) != map_width)
			return (-1);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2 || ft_strlen(argv[1]) <= 4 || ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4))
	{
		ft_printf("\n[❌] invalid map");
		return (1);
	}
	ft_printf("\n[✅] 😅 valid map\n");
	game = malloc(sizeof(game));
	get_map(argv[1], game);
	int res = is_map_valid(game);
	printf("Res: %d", res);
	return (0);
}
