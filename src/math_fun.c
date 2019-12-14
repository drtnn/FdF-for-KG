/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:58:27 by mnidoque          #+#    #+#             */
/*   Updated: 2019/12/02 21:58:35 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	diff(t_fdf p0, t_fdf p1)
{
	t_fdf	deltap;

	deltap.x = p1.x - p0.x;
	deltap.y = p1.y - p0.y;
	return (deltap);
}

void	radians(t_fdf *grads, t_rot *rads)
{
	double	rad_x;
	double	rad_y;
	double	rad_z;

	rad_x = DEG_TO_RAD(grads->x);
	rad_y = DEG_TO_RAD(grads->y);
	rad_z = DEG_TO_RAD(grads->z);
	rads->cosx = cos(rad_x);
	rads->sinx = sin(rad_x);
	rads->cosy = cos(rad_y);
	rads->siny = sin(rad_y);
	rads->cosz = cos(rad_z);
	rads->sinz = sin(rad_z);
}
