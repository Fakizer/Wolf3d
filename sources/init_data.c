/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 19:11:26 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/10/24 14:02:06 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_wolf2(t_wolf *w)
{
	w->max_y = 0;
	w->max_x = 0;
	w->map = NULL;
	w->hero_x = 0;
	w->hero_y = 0;
	w->units = 64;
	w->fov = 60;
	w->ray_x = 0;
	w->ray_y = 0;
	w->dist = (w->width / 2) / tan((w->fov / 2) * M_PI / 180);
	w->fov_step = w->fov / w->width;
	w->pov = 90;
	w->r1 = 0;
	w->r2 = 0;
	w->t = init_text();
	w->ray = init_ray();
	w->m.front_back = 0;
	w->m.left_right = 0;
	w->m.rot = 0;
}

t_wolf		*init_wolf(char *file)
{
	t_wolf	*w;

	if ((w = (t_wolf*)malloc(sizeof(t_wolf))) == NULL)
		return (NULL);
	if ((w->mlx = mlx_init()) == NULL)
		init_error(ERROR_MLX);
	w->width = 1024;
	w->height = 1024;
	if ((w->win = mlx_new_window(w->mlx, w->width, w->height, PROG_NAME))
		== NULL)
		init_error(ERROR_MLX);
	w->wolf = NULL;
	w->wolf_data = NULL;
	w->bpp = 0;
	w->end = 0;
	w->size_line = 0;
	w->file = file;
	init_wolf2(w);
	return (w);
}

t_ray		*init_ray(void)
{
	t_ray *ray;

	if ((ray = (t_ray*)malloc(sizeof(t_ray))) == NULL)
		return (NULL);
	ray->x = 0;
	ray->y = 0;
	ray->rx = 0;
	ray->ry = 0;
	ray->rad = 0;
	ray->r = 0;
	return (ray);
}

t_text		*init_text(void)
{
	t_text	*t;
	int		i;

	i = -1;
	if ((t = (t_text*)malloc(sizeof(t_text) * 4)) == NULL)
		return (NULL);
	while (++i < 4)
	{
		t->text = NULL;
		t->text_data = NULL;
		t->bpp = 0;
		t->end = 0;
		t->size_line = 0;
		t->w = 0;
		t->h = 0;
		t->img = 0;
	}
	return (t);
}
