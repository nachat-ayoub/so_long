/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:39:30 by anachat           #+#    #+#             */
/*   Updated: 2025/01/19 10:53:33 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

int	handle_error(char *msg, t_game *g)
{
	ft_putstr_fd(RED "Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(RESET, 2);
	return (exit_game(g), 1);
}
