/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:13:13 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/10/24 19:09:11 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_len_f(char *file)
{
	int		ret;
	int		len1;
	int		len2;
	char	*line;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == ERROR)
		init_error(file);
	ret = 0;
	len1 = 0;
	len2 = 0;
	get_next_line(fd, &line);
	len1 = ft_strlen(line);
	free(line);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		len2 = ft_strlen(line);
		if (len2 != len1)
			init_error("galimay mapa");
		free(line);
	}
	close(fd);
}

void	pers_coord(char *line, int i, t_wolf *w)
{
	int s;

	s = 0;
	while (line[s] && line[s] != 'x')
		s++;
	w->hero_x = s;
	w->hero_y = i;
	w->ray_x = w->hero_x * 64 - 32;
	w->ray_y = w->hero_y * 64 - 32;
}

void	check_file(char *file, t_wolf *w)
{
	char	*line;
	int		fd;
	int		ret;
	int		pers;
	int		i;

	if ((fd = open(file, O_RDONLY)) == ERROR)
		init_error(file);
	pers = 0;
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strchr(line, 'x'))
		{
			pers_coord(line, i, w);
			pers++;
		}
		free(line);
		i++;
	}
	if (pers != 1)
		init_error("I need more characters!!!!");
	close(fd);
	check_len_f(file);
}
