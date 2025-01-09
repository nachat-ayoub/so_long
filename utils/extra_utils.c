#include "../so_long.h"

void	count_map_elms(t_game *game, int *e, int *p, int *c)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (game->map && ++i < game->map_h)
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'E')
				(*e)++;
			if (game->map[i][j] == 'P')
				(*p)++;
			if (game->map[i][j] == 'C')
				(*c)++;
		}
	}
}
