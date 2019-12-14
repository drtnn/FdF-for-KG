/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:03:20 by mnidoque          #+#    #+#             */
/*   Updated: 2019/12/02 15:03:26 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	env_init(t_env *win)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "fdf");
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->bpp = 32;
	win->size_line = WIDTH;
	win->endian = 0;
	win->help = 0;
	win->gradient = 1;
	win->visible_lines = 1;
	win->pix_ptr = mlx_get_data_addr(win->img_ptr, &(win->bpp),
		&(win->size_line), &(win->endian));
	start_position(win);
	refresh_screen(win);
}

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		write(1, "Usage : ./fdf <filename> [ case_size z_size ]\n", 46);
		return (0);
	}
	if ((reading_file(&env, argv[1])) == -1)
	{
		write(1, "No data found.\n", 15);
		return (-1);
	}
	env_init(&env);
	mlx_hook(env.win_ptr, 2, 0, key_press, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
