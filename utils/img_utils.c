/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:22:56 by anachat           #+#    #+#             */
/*   Updated: 2025/01/18 16:06:47 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*load_img(void *mlx, char *img, int *size, t_game *g)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(mlx, img, size, size);
	if (!ptr)
		return (handle_error("Failed to load images", g), NULL);
	return (ptr);
}

int	put_img(t_game *g, void *img, int x, int y)
{
	int	r;

	r = mlx_put_image_to_window(g->mlx, g->win, img, x, y);
	return (r);
}

void	*get_img(t_game *g, int y, int x)
{
	void	*img;
	char	c;

	img = NULL;
	c = g->map[y][x];
	if (c == '1')
		img = g->img_wall;
	else if (c == 'E')
		img = g->img_exit;
	else if (c == 'C')
	{
		put_img(g, g->img_bg, g->b_size * x, g->b_size * y);
		img = g->img_coins;
	}
	else
		img = g->img_bg;
	return (img);
}
