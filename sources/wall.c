/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:09:17 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/10/24 14:03:43 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_wall1(t_wolf *w, int x, int y, int k)
{
	double	i;
	int		cast;

	cast = 0;
	y = -1;
	i = 0;
	w->t[k].img = 0;
	while (++y < w->height)
	{
		if (y > ((w->height / 2) - (w->psh / 2)) &&
			y < ((w->height / 2) + (w->psh / 2)))
		{
			if (((w->height / 2) - (w->psh / 2)) <= 0)
				i = ((w->psh - w->height) / 2.0) * ((double)w->t[k].h /
					w->psh);
			if (w->r1 < w->r2)
				cast = w->cast_x % (64);
			else
				cast = w->cast_y % (64);
			ft_memcpy(&w->wolf_data[(x * 4) + (w->size_line * y)],
			&w->t[k].text_data[(cast * 4 * 2) + (w->t[k].size_line *
				(int)(w->t[k].img + i))], 4);
			w->t[k].img += (double)w->t[k].h / w->psh;
		}
	}
}

void	draw_wall(t_wolf *w, int x, int y, int k)
{
	double	i;
	int		cast;

	cast = 0;
	y = -1;
	i = 0;
	w->t[k].img = 0;
	while (++y < w->height)
	{
		if (y > ((w->height / 2) - (w->psh / 2)) &&
			y < ((w->height / 2) + (w->psh / 2)))
		{
			if (((w->height / 2) - (w->psh / 2)) <= 0)
				i = ((w->psh - w->height) / 2.0) * ((double)w->t[k].h /
					w->psh);
			if (w->r1 < w->r2)
				cast = w->cast_x % (64);
			else
				cast = w->cast_y % (64);
			ft_memcpy(&w->wolf_data[(x * 4) + (w->size_line * y)],
			&w->t[k].text_data[(cast * 4) + (w->t[k].size_line *
				(int)(w->t[k].img + i))], 4);
			w->t[k].img += (double)w->t[k].h / w->psh;
		}
	}
}

void	wall_cast(double ang, double angle, t_wolf *w)
{
	double	r;
	t_ray	*ray;

	r = 0;
	ray = w->ray;
	if (angle == 0 || angle == 90 || angle == 180 || angle == 270)
		r = parc_zero(w, angle);
	else
	{
		w->r1 = ray_x(w, angle);
		w->r2 = ray_y(w, angle);
		ray->r = (int)w->r1 < (int)w->r2 ? w->r1 : w->r2;
		w->fxm = w->r1 < w->r2 ? w->fxv / 64.0 : w->fxg / 64.0;
		w->fym = w->r1 < w->r2 ? w->fyv / 64.0 : w->fyg / 64.0;
	}
	w->r = ray->r * cos(absd(ang) * M_PI / 180);
	w->psh = (64.0 / w->r) * w->dist;
}
