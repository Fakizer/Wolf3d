/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 13:30:00 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/10/24 19:08:05 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

size_t	count_lines(char *file)
{
	size_t	n;
	int		ret;
	char	*line;
	int		fd;

	n = 0;
	ret = ERROR;
	line = NULL;
	if ((fd = open(file, O_RDONLY)) == ERROR)
		init_error(file);
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret == ERROR)
			init_error(ERROR_PROC);
		free(line);
		n++;
	}
	if (close(fd) == ERROR)
		init_error(file);
	return (n);
}

void	max_x(t_wolf *w)
{
	int dup;
	int y;

	y = 0;
	while (w->map[y])
	{
		dup = ft_strlen(w->map[y]);
		if (w->max_x < dup)
			w->max_x = dup;
		y++;
	}
}

void	parcing_map(int fd, t_wolf *w)
{
	char	*line;
	int		ret;
	int		y;

	line = NULL;
	ret = ERROR;
	y = 0;
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret == ERROR)
			init_error(ERROR_PROC);
		w->map[y] = ft_strnew(ft_strlen(line));
		ft_strcpy(w->map[y], line);
		free(line);
		y++;
	}
	max_x(w);
}

void	parcing_file(char *file, t_wolf *w)
{
	int		fd;
	size_t	n_lines;

	fd = 0;
	n_lines = 0;
	if ((n_lines = count_lines(file)) == 0)
		init_error(EMPTYFILE);
	w->max_y = n_lines;
	w->map = (char **)malloc(sizeof(char *) * (n_lines + 1));
	if (w->map == NULL)
		init_error("");
	w->map[n_lines] = NULL;
	if ((fd = open(file, O_RDONLY)) == ERROR)
		init_error(file);
	parcing_map(fd, w);
	if (close(fd) == ERROR)
		init_error(file);
}
