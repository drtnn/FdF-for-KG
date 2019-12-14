/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:07:43 by mnidoque          #+#    #+#             */
/*   Updated: 2019/12/02 22:07:46 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_line(t_env *win, t_fdf p0, t_fdf p1)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			draw_low_line(win, p1, p0, diff(p1, p0));
		else
			draw_low_line(win, p0, p1, diff(p0, p1));
	}
	else
	{
		if (p0.y > p1.y)
			draw_top_line(win, p1, p0, diff(p1, p0));
		else
			draw_top_line(win, p0, p1, diff(p0, p1));
	}
}

void		draw_top_line(t_env *win, t_fdf p0, t_fdf p1,
							t_fdf deltap)
{
	t_fdf	p;
	int		d;
	int		xi;

	xi = 1;
	if (deltap.x < 0)
	{
		xi = -1;
		deltap.x = -deltap.x;
	}
	d = 2 * deltap.x - deltap.y;
	p.y = p0.y;
	p.x = p0.x;
	while (p.y <= p1.y)
	{
		(win->gradient == 0) ? put_pixel(win->pix_ptr, p.x, p.y, p0.color) :
			put_gr_pixel(p, p0, p1, win);
		if (d > 0)
		{
			p.x = p.x + xi;
			d = d - 2 * deltap.y;
		}
		d = d + 2 * deltap.x;
		p.y++;
	}
}

void		draw_low_line(t_env *win, t_fdf p0, t_fdf p1,
							t_fdf deltap)
{
	t_fdf	p;
	int		d;
	int		yi;

	yi = 1;
	if (deltap.y < 0)
	{
		yi = -1;
		deltap.y = -deltap.y;
	}
	d = 2 * deltap.y - deltap.x;
	p.y = p0.y;
	p.x = p0.x;
	while (p.x <= p1.x)
	{
		(win->gradient == 0) ? put_pixel(win->pix_ptr, p.x, p.y, p0.color) :
			put_gr_pixel(p, p0, p1, win);
		if (d > 0)
		{
			p.y += yi;
			d -= 2 * deltap.x;
		}
		d += 2 * deltap.y;
		p.x++;
	}
}
