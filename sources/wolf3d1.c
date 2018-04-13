/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:07:57 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/10/24 19:25:43 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		fps(t_wolf *w)
{
	static int	timestamp;
	static int	fps;
	static int	fps_2;
	char		*fpsm;

	if (time(NULL) != timestamp)
	{
		fps_2 = fps;
		fps = 0;
		timestamp = (int)time(NULL);
	}
	else
		fps++;
	fpsm = ft_itoa(fps_2);
	mlx_string_put(w->mlx, w->win, 10, 15, 0xFFFFFF, "FPS  :");
	mlx_string_put(w->mlx, w->win, 70, 15, 0xFFFFFF, fpsm);
	free(fpsm);
}

double		absd(double d)
{
	return (d = d < 0 ? -d : d);
}

int			mouse_exit(void)
{
	system("killall afplay");
	exit(0);
}
