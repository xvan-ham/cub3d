/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:03:53 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/15 17:07:29 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_press_key(int key, void *param)
{
	t_vectors	*v;

	v = (t_vectors *)(param);
	if (!v)
		ft_error("received null pointer: ft_press_key");
	if (key == KEY_ESC)
	{
		ft_putstr("\nPressed Esc, closing window - Bye! (FIX me)\n");
		exit(0);
	}
	if (key == KEY_W && !v->flag_key_w_down)
		v->flag_key_w_down = 1;
	if (key == KEY_S && !v->flag_key_s_down)
		v->flag_key_s_down = 1;
	if (key == KEY_D && !v->flag_key_d_down)
		v->flag_key_d_down = 1;
	if (key == KEY_A && !v->flag_key_a_down)
		v->flag_key_a_down = 1;
	if (key == KEY_RIGHT && !v->flag_key_right_down)
		v->flag_key_right_down = 1;
	if (key == KEY_LEFT && !v->flag_key_left_down)
		v->flag_key_left_down = 1;
	return (0);
}

int		ft_release_key(int key, void *param)
{
	t_vectors	*v;

	v = (t_vectors *)(param);
	if (!v)
		ft_error("received null pointer: ft_release_key");
	if (key == KEY_W)
		v->flag_key_w_down = 0;
	if (key == KEY_S)
		v->flag_key_s_down = 0;
	if (key == KEY_D)
		v->flag_key_d_down = 0;
	if (key == KEY_A)
		v->flag_key_a_down = 0;
	if (key == KEY_RIGHT)
		v->flag_key_right_down = 0;
	if (key == KEY_LEFT)
		v->flag_key_left_down = 0;
	return (0);
}
