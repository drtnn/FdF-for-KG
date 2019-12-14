/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:01:57 by mnidoque          #+#    #+#             */
/*   Updated: 2019/12/02 15:02:04 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	middle(t_env *win)
{
	win->fig_centre.x = win->mtrx.m[win->mtrx.rows / 2][win->mtrx.cols / 2].x
		* win->scale.x;
	win->fig_centre.y = win->mtrx.m[win->mtrx.rows / 2][win->mtrx.cols / 2].y
		* win->scale.y;
	win->fig_centre.z = win->mtrx.m[win->mtrx.rows / 2][win->mtrx.cols / 2].z
		* win->scale.z;
}

void	rotate(t_fdf *p, t_rot *rads, t_fdf *centre)
{
	int prev_x;
	int prev_y;
	int	prev_z;

	prev_y = p->y;
	prev_z = p->z;
	p->y = centre->y + (prev_y - centre->y) * rads->cosx +
			(prev_z - centre->z) * rads->sinx;
	p->z = centre->z + (prev_z - centre->z) * rads->cosx -
			(prev_y - centre->y) * rads->sinx;
	prev_x = p->x;
	prev_z = p->z;
	p->x = centre->x + (prev_x - centre->x) * rads->cosy -
			(prev_z - centre->z) * rads->siny;
	p->z = centre->z + (prev_z - centre->z) * rads->cosy +
			(prev_x - centre->x) * rads->siny;
	prev_x = p->x;
	prev_y = p->y;
	p->x = centre->x + (prev_x - centre->x) * rads->cosz +
			(prev_y - centre->y) * rads->sinz;
	p->y = centre->y + (prev_y - centre->y) * rads->cosz -
			(prev_x - centre->x) * rads->sinz;
}
