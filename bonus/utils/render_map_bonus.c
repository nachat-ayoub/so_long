/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:04:10 by anachat           #+#    #+#             */
/*   Updated: 2025/01/19 10:53:10 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	draw_map(t_game *g)
{
	void	*img;
	int		x;
	int		y;

	y = 0;
	while (y < g->map_h)
	{
		x = 0;
		while (g->map[y][x])
		{
			img = get_img(g, y, x);
			if (img)
				put_img(g, img, g->b_size * x, g->b_size * y);
			x++;
		}
		y++;
	}
	x = g->b_size * g->pl_x;
	y = g->b_size * g->pl_y;
	put_img(g, g->img_pl, x, y);
}
