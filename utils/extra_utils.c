#include "../so_long.h"

void	count_map_elms(t_game *game, int *e, int *p, int *c)
{
	int	i;
	int	j;

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

int count_char(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
