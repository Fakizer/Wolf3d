/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 18:59:33 by vvlasenk          #+#    #+#             */
/*   Updated: 2017/10/24 14:37:57 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# define PROG_NAME			"wolf3d"
# define ERROR_EXIT			1
# define ERROR				-1
# define ERROR_PROC			"error while reading file"
# define EMPTYFILE			"error: the file is empty"
# define ERROR_MLX			"minilibx error occured"
# define EXIT_OK			0

typedef enum				e_bool
{
	FT_FALSE,
	FT_TRUE
}							t_bool;

typedef enum				e_key
{
	ESC = 53,
	F1 = 122,
	ZOOM_UP = 4,
	ZOOM_DOWN = 5,
	HOME = 115,
	LEFT_MOUSE = 1,
	RIGHT_MOUSE = 2,
	A = 0,
	S = 1,
	D = 2,
	W = 13,
}							t_key;

typedef struct				s_text
{
	void					*text;
	char					*text_data;
	int						bpp;
	int						end;
	int						size_line;
	int						w;
	int						h;
	double					img;
	int						iam;
}							t_text;

typedef struct				s_ray
{
	int		x;
	int		y;
	double	rx;
	double	ry;
	double	rad;
	double	r;
}							t_ray;

typedef struct				s_move
{
	int front_back;
	int left_right;
	int rot;
}							t_move;

typedef struct				s_wolf
{
	void					*mlx;
	void					*win;
	int						max_y;
	int						max_x;
	char					**map;
	void					*wolf;
	char					*wolf_data;
	int						bpp;
	int						end;
	int						size_line;
	int						width;
	int						height;
	int						hero_x;
	int						hero_y;
	int						units;
	double					fov;
	double					pov;
	int						ray_x;
	int						ray_y;
	int						dist;
	double					fov_step;
	double					r1;
	double					r2;
	int						cast_x;
	int						cast_y;
	t_text					*t;
	t_ray					*ray;
	t_move					m;
	int						psh;
	double					fxv;
	double					fxg;
	double					fyg;
	double					fyv;
	double					fxm;
	double					fym;
	double					r;
	double					currentdist;
	int						floortexx;
	int						floortexy;
	double					weight;
	double					currentfloorx;
	double					currentfloory;
	char					*file;
}							t_wolf;

void						init_wolf2(t_wolf *w);
t_wolf						*init_wolf(char *file);
t_text						*init_text();
t_ray						*init_ray();
void						init_error(char *pref);
size_t						count_lines(char *file);
void						parcing_map(int fd, t_wolf *w);
void						parcing_file(char *file, t_wolf *w);
void						max_x(t_wolf *w);
double						ray_y(t_wolf *w, double angle);
void						ray_yy(t_ray *ray, double angle, t_wolf *w);
double						ray_x(t_wolf *w, double angle);
void						ray_xx(t_ray *ray, double angle, t_wolf *w);
double						parc_zero(t_wolf *w, double angle);
double						parc_zero1(t_ray *ray, double angle, t_wolf *w);
double						parc_zero2(t_ray *ray, double angle, t_wolf *w);
int							expose_hook(t_wolf *w);
int							mouse_exit(void);
void						move_hook(t_wolf *w);
void						move_right(t_wolf *w);
void						move_left(t_wolf *w);
void						move_front(t_wolf *w);
void						move_back(t_wolf *w);
void						rot_right(t_wolf *w);
void						rot_left(t_wolf *w);
int							key_hook(int keycode, t_wolf *w);
int							key_release(int keycode, t_wolf *w);
int							move_mouse(int x, int y, t_wolf *w);
void						draw_wall(t_wolf *w, int x, int y, int k);
void						draw_wall1(t_wolf *w, int x, int y, int k);
void						wall_cast(double ang, double angle, t_wolf *w);
double						absd(double d);
void						fps(t_wolf *e);
void						wolf_create(t_wolf *w);
void						textures(t_wolf *w);
void						draw_floor(t_wolf *w, int x, int y);
void						check_file(char *file, t_wolf *w);

#endif
