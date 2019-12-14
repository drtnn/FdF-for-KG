/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:59:07 by mnidoque          #+#    #+#             */
/*   Updated: 2019/12/02 21:59:10 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		menu(t_env *env)
{
	if (env->help == 1)
	{
		mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 20, 0xFFFFFF,
			"rotatinon: UP/DOWN       NUM8/NUM2");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 40, 0xFFFFFF,
			"           LEFT/RIGHT    NUM4/NUM6");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 60, 0xFFFFFF,
			"tilt:      LEFT/RIGHT    NUM7/NUM9");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 80, 0xFFFFFF,
			"reset:                   NUM0");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 100, 0xFFFFFF,
			"gradient:                G");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 120, 0xFFFFFF,
			"points:                  L");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 140, 0xFFFFFF,
			"iso:                     I");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 160, 0xFFFFFF,
			"perspective:             P");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 180, 0xFFFFFF,
			"restart:                 NUM0");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 200, 0xFFFFFF,
			"Exit:                    ESC");
	}
}

void		key_handler(int key, t_env *env)
{
	if (key == K_LEFT_ARROW || key == K_RIGTH_ARROW || key == K_UP_ARROW
		|| key == K_DOWN_ARROW)
		moving(key, env);
	if (key == K_NUM_MINUS || key == K_NUM_PLUS)
		zooming(key, env);
	if (key == K_NUM_7 || key == K_NUM_8 || key == K_NUM_9 || key == K_NUM_4
		|| key == K_NUM_2 || key == K_NUM_6)
		rotation(key, env);
	if (key == K_NUM_1 || key == K_NUM_3)
		zooming_height(key, env);
	if (key == K_NUM_0 || key == K_P)
		start_position(env);
	if (key == K_ESC)
		exit(0);
	if (key == K_H)
		env->help = !(env->help);
	if (key == K_G)
		env->gradient = !(env->gradient);
	if (key == K_L)
		env->visible_lines = !(env->visible_lines);
	if (key == K_I)
		iso_position(env);
	refresh_screen(env);
}

int			key_press(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	key_handler(key, env);
	return (0);
}

void		iso_position(t_env *env)
{
	env->fig_pos.x = WIDTH / 2;
	env->fig_pos.y = HEIGHT / 2;
	env->grads.x = 0;
	env->grads.y = 0;
	env->grads.z = 0;
	env->scale.x = 20;
	env->scale.y = 20;
	env->scale.z = 20;
}

void		start_position(t_env *env)
{
	env->fig_pos.x = WIDTH / 2;
	env->fig_pos.y = HEIGHT / 2;
	env->grads.x = -30;
	env->grads.y = 30;
	env->grads.z = -30;
	env->scale.x = 20;
	env->scale.y = 20;
	env->scale.z = 20;
}
