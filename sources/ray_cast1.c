/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 19:18:18 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/01/06 19:18:18 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	parc_zero1(t_ray *ray, double angle, t_wolf *w)
{
	if (angle == 0)
		ray->rx = (w->ray_x / 64) * 64 + 64;
	else
		ray->rx = (w->ray_x / 64) * 64 - 0.00001;
	ray->rx = ray->rx > 0 ? ray->rx : 0;
	ray->y = w->ray_y / 64;
	ray->x = ray->rx / 64;
	while (ray->x < w->max_x && ray->y < w->max_y
		&& w->map[ray->y][ray->x] < '1')
	{
		if (angle == 0)
			ray->rx += 64.0;
		else
			ray->rx -= 64.0;
		ray->rx = ray->rx > 0 ? ray->rx : 0;
		ray->y = w->ray_y / 64;
		ray->x = ray->rx / 64;
	}
	return (absd(w->ray_x - ray->rx));
}

double	parc_zero2(t_ray *ray, double angle, t_wolf *w)
{
	if (angle == 270)
		ray->ry = (w->ray_x / 64) * 64 + 64;
	else
		ray->ry = (w->ray_x / 64) * 64 - 0.00001;
	ray->ry = ray->ry > 0 ? ray->ry : 0;
	ray->y = ray->ry / 64;
	ray->x = w->ray_x / 64;
	while (ray->x < w->max_x && ray->y < w->max_y
		&& w->map[ray->y][ray->x] < '1')
	{
		if (angle == 270)
			ray->ry += 64.0;
		else
			ray->ry -= 64.0;
		ray->ry = ray->ry > 0 ? ray->ry : 0;
		ray->y = ray->ry / 64;
		ray->x = w->ray_x / 64;
	}
	return (absd(w->ray_y - ray->ry));
}
