#include "so_long.h"

// int is_map_valid(t_game *game)
// {
// 	int 	i;
// 	size_t map_width;

	
// 	i = 0;
// 	while (game->map && i < game->win_h)
// 	{ 
// 		printf(BLUE "Line: %s\n" RESET, game->map[i]);
// 		// rectangular map shape check
// 		if (ft_strlen(game->map[i]) != map_width)
// 			return (-1);
// 		// walls check on left
// 		if (game->map[i][0] != '1')
// 					return (-3);
// 		// walls check on right
// 		if (game->map[i][game->win_w-1] != '1')
// 					return (-2);
// 		// walls check on top and bottom
// 		if(i == 0 || i == game->win_h-1)
// 		{
// 			int j = 0;
// 			while (game->map[i][j])
// 			{
// 				if (game->map[i][j] != '1')
// 					return (-1);
// 				j++;
// 			}
			
// 		}
// 		i++;
// 	}
// 	return (1);
// }

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2 || ft_strlen(argv[1]) <= 4 || ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 5) != 0)
	{
		ft_printf("\n[❌] invalid map argument");
		return (1);
	}
	ft_printf("\n[✅] 😅 valid map\n");
	// game = malloc(sizeof(game));
	game = NULL;
	if (!game)
		return (0);
	get_map(argv[1], game);
	game->map_w = ft_strlen(game->map[0]);

	printf(YELLOW "Map W: %zu\n" RESET, game->map_w);
	printf(YELLOW "Map H: %zu\n" RESET, game->map_h);
	int res = is_map_valid(game);
	if (res == 1)
		printf(GREEN "=========[ Valid Map: %d ]=========\n" RESET, res);
	else
		printf(RED   "=========[ Invalid Map: %d ]=========\n" RESET, res);
	return (0);
}
