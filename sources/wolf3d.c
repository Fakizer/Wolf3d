/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 18:59:09 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/10/24 19:20:23 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		parcing_cast(int x, double ang, double angle, t_wolf *w)
{
	int		y;

	y = 0;
	wall_cast(ang, angle, w);
	if (w->map[(int)w->fym][(int)w->fxm] == '1')
		draw_wall(w, x, y, 0);
	if (w->map[(int)w->fym][(int)w->fxm] == '2')
		draw_wall1(w, x, y, 1);
	draw_floor(w, x, y);
}

void		wolf_create(t_wolf *w)
{
	double	angle;
	int		x;
	double	ang;

	x = 0;
	ang = -w->fov / 2;
	angle = w->pov - (w->fov / 2);
	x = w->width - 1;
	while (x >= 0)
	{
		angle = angle < 0 ? 360 + angle : angle;
		angle = angle >= 360 ? angle - 360 : angle;
		parcing_cast(x, ang, angle, w);
		x--;
		angle += w->fov_step;
		ang += w->fov_step;
	}
}

char		*get_textures(int i)
{
	if (i == 0)
		return ("./textures/wall/w1.xpm");
	else if (i == 1)
		return ("./textures/wall/images.xpm");
	else if (i == 2)
		return ("./textures/wall/b1.xpm");
	else if (i == 3)
		return ("./textures/wall/b2.xpm");
	return (NULL);
}

void		textures(t_wolf *w)
{
	t_text	*t;
	int		i;

	i = -1;
	t = w->t;
	while (++i < 4)
	{
		t[i].text = mlx_xpm_file_to_image(w->mlx, get_textures(i),
			&t[i].w, &t[i].h);
		t[i].text_data = mlx_get_data_addr(t[i].text, &t[i].bpp,
		&t[i].size_line, &t[i].end);
	}
}

int			main(int ac, char **av)
{
	t_wolf		*w;

	if (ac != 2)
		init_error("Gde mapa?!!!");
	if ((w = init_wolf(av[1])) == NULL)
		init_error("");
	textures(w);
	check_file(w->file, w);
	parcing_file(w->file, w);
	system("afplay ./textures/LS.mp3&");
	mlx_hook(w->win, 2, (1L << 0), key_hook, w);
	mlx_hook(w->win, 3, (1L << 1), key_release, w);
	mlx_hook(w->win, 17, 0, mouse_exit, 0);
	mlx_loop_hook(w->mlx, expose_hook, w);
	mlx_loop(w->mlx);
}
