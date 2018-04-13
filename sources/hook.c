/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:35:40 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/10/24 14:10:47 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose_hook(t_wolf *w)
{
	if ((w->wolf = mlx_new_image(w->mlx, w->width, w->height)) == NULL)
		init_error(ERROR_MLX);
	w->wolf_data = mlx_get_data_addr(w->wolf, &w->bpp,
		&w->size_line, &w->end);
	wolf_create(w);
	mlx_put_image_to_window(w->mlx, w->win, w->wolf, 0, 0);
	move_hook(w);
	fps(w);
	mlx_destroy_image(w->mlx, w->wolf);
	return (0);
}

void	move_hook(t_wolf *w)
{
	if (w->m.left_right == -1)
		move_left(w);
	if (w->m.left_right == 1)
		move_right(w);
	if (w->m.front_back == -1)
		move_back(w);
	if (w->m.front_back == 1)
		move_front(w);
	if (w->m.rot == -1)
		rot_left(w);
	if (w->m.rot == 1)
		rot_right(w);
}

void	move_right(t_wolf *w)
{
	double x;
	double y;

	x = w->ray_x + 16.0 * sin(w->pov * M_PI / 180);
	y = w->ray_y + 16.0 * cos(w->pov * M_PI / 180);
	if ((w->map[(int)(y / 64.0 + 0.1)][(int)(x / 64.0 + 0.1)]) &&
		(w->map[(int)(y / 64.0 - 0.1)][(int)(x / 64.0 - 0.1)]))
	{
		if ((w->map[(int)(y / 64.0 + 0.1)][(int)(x / 64.0)] < '1') &&
			(w->map[(int)(y / 64.0 - 0.1)][(int)(x / 64.0)] < '1'))
			w->ray_y = y;
		if ((w->map[(int)(y / 64.0)][(int)(x / 64.0 + 0.1)] < '1') &&
			(w->map[(int)(y / 64.0)][(int)(x / 64.0 - 0.1)] < '1'))
			w->ray_x = x;
	}
}

void	move_left(t_wolf *w)
{
	double x;
	double y;

	x = w->ray_x - 16.0 * sin(w->pov * M_PI / 180);
	y = w->ray_y - 16.0 * cos(w->pov * M_PI / 180);
	if ((w->map[(int)(y / 64.0 + 0.1)][(int)(x / 64.0 + 0.1)]) &&
		(w->map[(int)(y / 64.0 - 0.1)][(int)(x / 64.0 - 0.1)]))
	{
		if ((w->map[(int)(y / 64.0 + 0.1)][(int)(x / 64.0)] < '1') &&
			(w->map[(int)(y / 64.0 - 0.1)][(int)(x / 64.0)] < '1'))
			w->ray_y = y;
		if ((w->map[(int)(y / 64.0)][(int)(x / 64.0 + 0.1)] < '1') &&
			(w->map[(int)(y / 64.0)][(int)(x / 64.0 - 0.1)] < '1'))
			w->ray_x = x;
	}
}

void	move_front(t_wolf *w)
{
	double x;
	double y;

	x = w->ray_x + 16.0 * cos(w->pov * M_PI / 180);
	y = w->ray_y - 16.0 * sin(w->pov * M_PI / 180);
	if ((w->map[(int)(y / 64.0 + 0.1)][(int)(x / 64.0 + 0.1)]) &&
		(w->map[(int)(y / 64.0 - 0.1)][(int)(x / 64.0 - 0.1)]))
	{
		if ((w->map[(int)(y / 64.0 + 0.1)][(int)(x / 64.0)] < '1') &&
			(w->map[(int)(y / 64.0 - 0.1)][(int)(x / 64.0)] < '1'))
			w->ray_y = y;
		if ((w->map[(int)(y / 64.0)][(int)(x / 64.0 + 0.1)] < '1') &&
			(w->map[(int)(y / 64.0)][(int)(x / 64.0 - 0.1)] < '1'))
			w->ray_x = x;
	}
}
