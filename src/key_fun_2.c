/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fun_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:44:35 by mnidoque          #+#    #+#             */
/*   Updated: 2019/12/02 21:44:40 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	moving(int key, t_env *env)
{
	if (key == K_LEFT_ARROW)
		env->fig_pos.x -= MOVE_POWER;
	else if (key == K_RIGTH_ARROW)
		env->fig_pos.x += MOVE_POWER;
	else if (key == K_DOWN_ARROW)
		env->fig_pos.y += MOVE_POWER;
	else if (key == K_UP_ARROW)
		env->fig_pos.y -= MOVE_POWER;
}

void	zooming(int key, t_env *env)
{
	if (key == K_NUM_PLUS)
	{
		env->scale.x++;
		env->scale.y++;
		env->scale.z++;
	}
	else if (key == K_NUM_MINUS)
	{
		env->scale.x--;
		env->scale.y--;
		env->scale.z--;
	}
}

void	zooming_height(int key, t_env *env)
{
	if (key == K_NUM_1)
		env->scale.z--;
	else if (key == K_NUM_3)
		env->scale.z++;
}

void	rotation(int key, t_env *env)
{
	if (key == K_NUM_2)
		env->grads.x += ROT_POWER;
	else if (key == K_NUM_8)
		env->grads.x -= ROT_POWER;
	else if (key == K_NUM_4)
		env->grads.y += ROT_POWER;
	else if (key == K_NUM_6)
		env->grads.y -= ROT_POWER;
	else if (key == K_NUM_7)
		env->grads.z += ROT_POWER;
	else if (key == K_NUM_9)
		env->grads.z -= ROT_POWER;
}
