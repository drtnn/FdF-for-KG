/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:11:15 by mnidoque          #+#    #+#             */
/*   Updated: 2019/12/02 22:11:20 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(char *pixels, int x, int y, int color)
{
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
		*(int *)(pixels + (WIDTH * y + x) * 4) = color;
}

void	put_gr_pixel(t_fdf p, t_fdf start,
			t_fdf end, t_env *win)
{
	t_fdf	delta;

	delta.x = abs(start.x - end.x);
	delta.y = abs(start.y - end.y);
	put_pixel(win->pix_ptr, p.x, p.y,
			gr_color(p, start, end, delta));
}

int		gr_color(t_fdf current, t_fdf start,
			t_fdf end, t_fdf delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = transition((start.color >> 16) & 0xFF,
		(end.color >> 16) & 0xFF, percentage);
	green = transition((start.color >> 8) & 0xFF,
		(end.color >> 8) & 0xFF, percentage);
	blue = transition(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		transition(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}
