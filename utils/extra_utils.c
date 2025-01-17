/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:39:30 by anachat           #+#    #+#             */
/*   Updated: 2025/01/16 14:38:14 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	count_char(char *str, char c)
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

int	handle_error(char *msg, t_game *g, int code)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	if(code == -1)
		return (free(g->map), free(g), exit(1), 1);
	if(code == -2)
		return (exit_game(g), 1);
	else
		return (1);
}
