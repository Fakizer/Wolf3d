/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:12:25 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/10/24 14:05:27 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_floor(t_wolf *w, int x, int y)
{
	w->currentdist = 0;
	w->floortexx = 0;
	w->floortexy = 0;
	w->weight = 0;
	w->currentfloorx = 0;
	w->currentfloory = 0;
	y = ((w->height / 2) + (w->psh / 2)) - 1;
	while (++y < w->height)
	{
		w->currentdist = w->height / (2.0 * y - w->height);
		w->weight = w->currentdist / (w->r / 64.0);
		w->currentfloorx = w->weight * w->fxm + (1.0 - w->weight) *
		(w->ray_x / 64.0);
		w->currentfloory = w->weight * w->fym + (1.0 - w->weight) *
		(w->ray_y / 64.0);
		w->floortexx = (int)(w->currentfloorx * w->t[2].w) % w->t[2].w;
		w->floortexy = (int)(w->currentfloory * w->t[2].h) % w->t[2].h;
		ft_memcpy(&w->wolf_data[(x * 4) + (w->size_line * (w->height - y))],
			&w->t[3].text_data[(w->floortexx * 4) +
				(w->t[3].size_line * w->floortexy)], 4);
		ft_memcpy(&w->wolf_data[(x * 4) + (w->size_line * y)],
			&w->t[2].text_data[(w->floortexx * 4) +
				(w->t[2].size_line * w->floortexy)], 4);
	}
}
