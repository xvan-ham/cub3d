/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:08:00 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/17 20:35:45 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	flag_w(t_vectors *v, int flag)
{
	if (flag)
	{
		if (v->map[(int)(v->pos_y + v->dir_y * v->move_speed)][(int)(v->pos_x)]
		== '0' && (int)(v->pos_y + v->dir_y * v->move_speed) &&
		(int)(v->pos_y + v->dir_y * v->move_speed) < v->map_height - 1)
			v->pos_y += v->dir_y * v->move_speed;
		if (v->map[(int)(v->pos_y)][(int)(v->pos_x + v->dir_x * v->move_speed)]
		== '0' && (int)(v->pos_x + v->dir_x * v->move_speed) &&
		(int)(v->pos_x + v->dir_x * v->move_speed) < v->map_width - 1)
			v->pos_x += v->dir_x * v->move_speed;
	}
}

static void	flag_s(t_vectors *v, int flag)
{
	if (flag)
	{
		if (v->map[(int)(v->pos_y - v->dir_y * v->move_speed)][(int)(v->pos_x)]
		== '0' && (int)(v->pos_y - v->dir_y * v->move_speed) &&
		(int)(v->pos_y - v->dir_y * v->move_speed) < v->map_height - 1)
			v->pos_y -= v->dir_y * v->move_speed;
		if (v->map[(int)(v->pos_y)][(int)(v->pos_x - v->dir_x * v->move_speed)]
		== '0' && (int)(v->pos_x - v->dir_x * v->move_speed) &&
		(int)(v->pos_x - v->dir_x * v->move_speed) < v->map_width - 1)
			v->pos_x -= v->dir_x * v->move_speed;
	}
}

static void	flag_a(t_vectors *v, int flag)
{
	if (flag)
	{
		if (v->map[(int)(v->pos_y - v->plane_y * v->move_speed)][(int)
		(v->pos_x)] == '0' && (int)(v->pos_y + v->plane_y * v->move_speed) &&
		(int)(v->pos_y + v->plane_y * v->move_speed) < v->map_height - 1)
			v->pos_y -= v->plane_y * v->move_speed;
		if (v->map[(int)(v->pos_y)][(int)(v->pos_x - v->plane_x *
		v->move_speed)] == '0' && (int)(v->pos_x + v->plane_x *
		v->move_speed) && (int)(v->pos_x + v->plane_x * v->move_speed)
		< v->map_width - 1)
			v->pos_x -= v->plane_x * v->move_speed;
	}
}

static void	flag_d(t_vectors *v, int flag)
{
	if (flag)
	{
		if (v->map[(int)(v->pos_y + v->plane_y * v->move_speed)][(int)
		(v->pos_x)] == '0' && (int)(v->pos_y + v->plane_y * v->move_speed) &&
		(int)(v->pos_y + v->plane_y * v->move_speed) < v->map_height - 1)
			v->pos_y += v->plane_y * v->move_speed;
		if (v->map[(int)(v->pos_y)][(int)(v->pos_x + v->plane_x *
		v->move_speed)] == '0' && (int)(v->pos_x + v->plane_x *
		v->move_speed) && (int)(v->pos_x + v->plane_x * v->move_speed)
		< v->map_width - 1)
			v->pos_x += v->plane_x * v->move_speed;
	}
}

int			ft_move(t_vectors *v)
{
	if (!v)
		ft_error("received null pointer: ft_move");
	flag_w(v, v->flag_key_w_down);
	flag_s(v, v->flag_key_s_down);
	flag_a(v, v->flag_key_a_down);
	flag_d(v, v->flag_key_d_down);
	flag_right(v, v->flag_key_right_down);
	flag_left(v, v->flag_key_left_down);
	ft_raycasting(v);
	ft_raycasting_sprite(v);
	return (0);
}
