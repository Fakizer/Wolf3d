/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:10:11 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/10/24 14:10:38 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_back(t_wolf *w)
{
	double x;
	double y;

	x = w->ray_x - 16.0 * cos(w->pov * M_PI / 180);
	y = w->ray_y + 16.0 * sin(w->pov * M_PI / 180);
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

void	rot_right(t_wolf *w)
{
	w->pov = (w->pov - 5);
	w->pov = w->pov < 0 ? 360 + w->pov : w->pov;
	w->pov = w->pov >= 360 ? w->pov - 360 : w->pov;
}

void	rot_left(t_wolf *w)
{
	w->pov = (w->pov + 5);
	w->pov = w->pov < 0 ? 360 + w->pov : w->pov;
	w->pov = w->pov >= 360 ? w->pov - 360 : w->pov;
}

int		key_hook(int keycode, t_wolf *w)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(w->mlx, w->win);
		system("killall afplay");
		exit(EXIT_OK);
	}
	else if (keycode == 123 || keycode == 124)
		w->m.rot = (keycode == 123 ? -1 : 1);
	else if (keycode == A || keycode == D)
		w->m.left_right = (keycode == A ? -1 : 1);
	else if (keycode == W || keycode == S)
		w->m.front_back = (keycode == S ? -1 : 1);
	return (0);
}

int		key_release(int keycode, t_wolf *w)
{
	if (keycode == W || keycode == S)
		w->m.front_back = 0;
	else if (keycode == A || keycode == D)
		w->m.left_right = 0;
	else if (keycode == 123 || keycode == 124)
		w->m.rot = 0;
	return (0);
}
