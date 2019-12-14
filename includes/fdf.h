/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:26:52 by mnidoque          #+#    #+#             */
/*   Updated: 2019/12/02 15:26:56 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include "libft.h"
# include "get_next_line.h"

# define E_NOFILE -1
# define E_NOMEMORY -2
# define E_BADMAP -3
# define E_EMPTY_FILE -4

# define K_LEFT_ARROW 123
# define K_RIGTH_ARROW 124
# define K_UP_ARROW 126
# define K_DOWN_ARROW 125
# define K_NUM_PLUS 69
# define K_NUM_MINUS 78
# define K_NUM_0 82

# define K_NUM_7 89
# define K_NUM_4 86
# define K_NUM_8 91
# define K_NUM_6 88
# define K_NUM_2 84
# define K_NUM_9 92
# define K_NUM_3 85
# define K_NUM_1 83

# define K_ESC 53

# define K_H 4
# define K_G 5
# define K_L 37
# define K_I 34
# define K_P 35
# define WIDTH 1600
# define HEIGHT 900
# define MOVE_POWER 5
# define ROT_POWER 2

# define P_PAR 0
# define P_ISO 1

# define C_RED 0xFF0000
# define C_GREEN 0x00FF00
# define C_BLUE 0x0000FF
# define C_WHITE 0xFFFFFF
# define C_YELLOW 0xD8CE0F
# define PI 3.14159265358979323846
# define DEG_TO_RAD(angle) (PI * angle) / 180

typedef struct	s_fdf
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_fdf;

typedef struct	s_rot
{
	double		cosx;
	double		sinx;
	double		cosy;
	double		siny;
	double		cosz;
	double		sinz;
}				t_rot;

typedef struct	s_matrix
{
	t_fdf		**m;
	int			rows;
	int			cols;
}				t_matrix;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*pix_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	int			help;
	int			gradient;
	int			visible_lines;
	t_fdf		scale;
	t_matrix	mtrx;
	t_matrix	draw_mtrx;
	t_fdf		grads;
	t_fdf		fig_pos;
	t_fdf		fig_centre;
	t_rot		rads;
}				t_env;

/*
** reading
*/

int				reading_file(t_env *win, char *fname);
int				ft_get_color(char *data, int z);
int				ft_hex_to_dec(char *hex);
int				ft_2darr_len(char **arr);
void			ft_del_2darr(char **arr);
void			ft_del_list(t_list **lst);

/*
** color_fun
*/

void			put_pixel(char *pixels, int x, int y, int color);
void			put_gr_pixel(t_fdf p, t_fdf start,
							t_fdf end, t_env *env);
int				gr_color(t_fdf current, t_fdf start,
							t_fdf end, t_fdf delta);
int				transition(int start, int end, double percentage);
double			percent(int start, int end, int current);

/*
** math_fun
*/

t_fdf			diff(t_fdf p0, t_fdf p1);
void			radians(t_fdf *grads, t_rot *rads);

/*
** line_fun
*/

void			draw_line(t_env *win, t_fdf p0, t_fdf p1);
void			draw_top_line(t_env *win, t_fdf p0, t_fdf p1,
							t_fdf deltap);
void			draw_low_line(t_env *win, t_fdf p0, t_fdf p1,
							t_fdf deltap);

/*
** dots_fun
*/

void			transfor_dots(t_env *env);
void			put_dots(t_env *env);
void			refresh_screen(t_env *env);
void			display_dots(t_env *win);

/*
** key_fun
*/

void			menu(t_env *env);
void			key_handler(int key, t_env *env);
int				key_press(int key, void *param);
void			start_position(t_env *env);
void			iso_position(t_env *env);

/*
** key_fun_2
*/

void			moving(int key, t_env *env);
void			zooming(int key, t_env *env);
void			zooming_height(int key, t_env *env);
void			rotation(int key, t_env *env);

/*
** rotation
*/

void			iso_view(t_fdf *p, t_fdf *centre);
void			rotate(t_fdf *p, t_rot *rads, t_fdf *centre);
void			middle(t_env *win);

#endif
