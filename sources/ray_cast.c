/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:14:42 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/01/03 14:14:43 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double		parc_zero(t_wolf *w, double angle)
{
	t_ray	*ray;

	ray = w->ray;
	if (angle == 0 || angle == 180)
		return (parc_zero1(ray, angle, w));
	if (angle == 90 || angle == 270)
		return (parc_zero2(ray, angle, w));
	return (0);
}

void		ray_yy(t_ray *ray, double angle, t_wolf *w)
{
	while (ray->x < w->max_x && ray->y < w->max_y
		&& w->map[ray->y][ray->x] < '1')
	{
		if (angle > 90 && angle < 270)
			ray->rx -= 64.0;
		else
			ray->rx += 64.0;
		if (angle > 0 && angle < 180)
			ray->ry = ray->ry - (64.0 * absd(tan(ray->rad)));
		else
			ray->ry = ray->ry + (64.0 * absd(tan(ray->rad)));
		ray->ry = ray->ry > 0 ? ray->ry : 0;
		ray->rx = ray->rx > 0 ? ray->rx : 0;
		ray->y = ray->ry / 64;
		ray->x = ray->rx / 64;
	}
}

double		ray_y(t_wolf *w, double angle)
{
	t_ray	*ray;
	double	x;
	double	y;

	x = 0;
	y = 0;
	ray = w->ray;
	ray->rad = (angle * M_PI) / 180;
	if (angle > 90 && angle < 270)
		ray->rx = (w->ray_x / 64) * 64 - 0.00001;
	else
		ray->rx = (w->ray_x / 64) * 64 + 64.0;
	ray->ry = w->ray_y + (w->ray_x - ray->rx) * tan(ray->rad);
	ray->ry = ray->ry > 0 ? ray->ry : 0;
	ray->rx = ray->rx > 0 ? ray->rx : 0;
	ray->y = ray->ry / 64;
	ray->x = ray->rx / 64;
	ray_yy(ray, angle, w);
	w->cast_y = ray->ry;
	w->fyg = ray->ry;
	w->fxg = ray->rx;
	x = (w->ray_x - ray->rx) * (w->ray_x - ray->rx);
	y = (w->ray_y - ray->ry) * (w->ray_y - ray->ry);
	return (sqrt(x + y));
}

void		ray_xx(t_ray *ray, double angle, t_wolf *w)
{
	while (ray->x < w->max_x && ray->y < w->max_y
		&& w->map[ray->y][ray->x] < '1')
	{
		if (angle > 0 && angle < 180)
			ray->ry -= 64.0;
		else
			ray->ry += 64.0;
		if (angle > 90 && angle < 270)
			ray->rx = ray->rx - (64.0 / absd(tan(ray->rad)));
		else
			ray->rx = ray->rx + (64.0 / absd(tan(ray->rad)));
		ray->ry = ray->ry > 0 ? ray->ry : 0;
		ray->rx = ray->rx > 0 ? ray->rx : 0;
		ray->y = ray->ry / 64;
		ray->x = ray->rx / 64;
	}
}

double		ray_x(t_wolf *w, double angle)
{
	t_ray	*ray;
	double	x;
	double	y;

	x = 0;
	y = 0;
	ray = w->ray;
	ray->rad = (angle * M_PI) / 180;
	if (angle > 0 && angle < 180)
		ray->ry = (w->ray_y / 64) * 64 - 0.00001;
	else
		ray->ry = (w->ray_y / 64) * 64 + 64.0;
	ray->rx = w->ray_x + (w->ray_y - ray->ry) / tan(ray->rad);
	ray->ry = ray->ry > 0 ? ray->ry : 0;
	ray->rx = ray->rx > 0 ? ray->rx : 0;
	ray->y = ray->ry / 64;
	ray->x = ray->rx / 64;
	ray_xx(ray, angle, w);
	w->cast_x = ray->rx;
	w->fyv = ray->ry;
	w->fxv = ray->rx;
	x = (w->ray_x - ray->rx) * (w->ray_x - ray->rx);
	y = (w->ray_y - ray->ry) * (w->ray_y - ray->ry);
	return (sqrt(x + y));
}
