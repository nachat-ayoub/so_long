#include "../so_long.h"

int	is_map_valid(t_game *game)
{
	int res;

	res = 1;
	if (is_rectangular(game) != 1)
	{
		res = -1;
		printf(MAGENTA "[MAP] map is not rectangular\n" RESET);
	}
	else if (has_valid_walls(game) != 1)
	{
		res = -2;
		printf(MAGENTA "[MAP] map does not have walls on sides\n" RESET);
	}
	else if (has_required_elements(game) != 1)
	{
		res = -3;
		printf(MAGENTA "[MAP] map does not have correct elements\n" RESET);
	}
	else if (has_valid_characters(game) != 1)
	{
		res = -4;
		printf(MAGENTA "[MAP] map has invalid characters\n" RESET);
	}
	else if (is_path_valid(game) != 1)
	{
		res = -5;
		printf(MAGENTA "[MAP] map has invalid path\n" RESET);
	}
	return (res);
}

// Checks if the map is rectangular (all rows have the same length).
int	is_rectangular(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->map_h)
	{
		if (ft_strlen(game->map[i]) != game->map_w)
			return (-1);
		i++;
	}
	return (1);
}

// Validates that the map is surrounded by walls ('1') on all edges.
int	has_valid_walls(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map && i < game->map_h)
	{
		// walls check on left
		if (game->map[i][0] != '1')
			return (-1);
		// walls check on right
		if (game->map[i][game->map_w - 1] != '1')
			return (-1);
		// walls check on top and bottom
		if (i == 0 || i == game->map_h - 1)
		{
			j = 0;
			while (game->map[i][j])
			{
				if (game->map[i][j] != '1')
					return (-1);
				j++;
			}
		}
		i++;
	}
	return (1);
}

// Checks if the map contains at least one collectible
// ('C'), one exit ('E'), and one starting position ('P').
int	has_required_elements(t_game *game)
{
	int		e;
	int		p;
	int		c;

	e = 0;
	p = 0;
	c = 0;
	count_map_elms(game, &e, &p, &c);
	if (e != 1 || p != 1 || c < 1)
		return (-1);
	return (1);
}

// Checks if all characters in the map are valid (e.g., '0', '1', 'C', 'E', 'P').
int		has_valid_characters(t_game *game)
{
	size_t	i;
	size_t	j;
	char	c;

	i = -1;
	while (game->map && ++i < game->map_h)
	{
		j = -1;
		while (game->map[i][++j])
		{
			c = game->map[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (-1);
		}
	}
	return (1);
}
