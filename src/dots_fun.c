/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:09:26 by mnidoque          #+#    #+#             */
/*   Updated: 2019/12/02 22:09:29 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transfor_dots(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->mtrx.rows)
	{
		j = -1;
		while (++j < env->mtrx.cols)
		{
			env->draw_mtrx.m[i][j].x = env->mtrx.m[i][j].x * (env->scale.x);
			env->draw_mtrx.m[i][j].y = env->mtrx.m[i][j].y * (env->scale.y);
			env->draw_mtrx.m[i][j].z = env->mtrx.m[i][j].z * (env->scale.z);
			rotate(&(env->draw_mtrx.m[i][j]), &(env->rads),
					&(env->fig_centre));
			env->draw_mtrx.m[i][j].x += (env->fig_pos.x -
				(env->mtrx.cols - 1) * env->scale.x / 2);
			env->draw_mtrx.m[i][j].y += (env->fig_pos.y -
				(env->mtrx.rows - 1) * env->scale.y / 2);
			env->draw_mtrx.m[i][j].color = env->mtrx.m[i][j].color;
		}
	}
}

void	put_dots(t_env *env)
{
	int			i;
	int			j;
	t_matrix	*m;

	m = &(env->draw_mtrx);
	i = -1;
	while (++i < m->rows - 1)
	{
		j = -1;
		while (++j < m->cols - 1)
			put_pixel(env->pix_ptr, m->m[i][j].x, m->m[i][j].y,
				m->m[i][j].color);
	}
}

void	refresh_screen(t_env *env)
{
	ft_bzero(env->pix_ptr, WIDTH * HEIGHT * sizeof(int));
	radians(&(env->grads), &(env->rads));
	middle(env);
	transfor_dots(env);
	if (env->visible_lines)
		display_dots(env);
	else
		put_dots(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	menu(env);
}

void	display_dots(t_env *env)
{
	int			i;
	int			j;
	t_matrix	*m;

	m = &(env->draw_mtrx);
	i = -1;
	while (++i < m->rows - 1)
	{
		j = -1;
		while (++j < m->cols - 1)
		{
			draw_line(env, m->m[i][j], m->m[i][j + 1]);
			draw_line(env, m->m[i][j], m->m[i + 1][j]);
		}
		draw_line(env, m->m[i][m->cols - 1],
			m->m[i + 1][m->cols - 1]);
	}
	i = -1;
	while (++i < m->cols - 1)
		draw_line(env, m->m[m->rows - 1][i],
			m->m[m->rows - 1][i + 1]);
}
