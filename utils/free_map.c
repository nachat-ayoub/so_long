#include "../so_long.h"

void    free_map(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->map_h)
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
	}
	free(game->map);
	game->map = NULL;
}
