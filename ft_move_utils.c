/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:49:40 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/14 19:51:41 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flag_right(t_vectors *v, int flag)
{
	double	olddir_y;
	double	oldplane_y;

	if (flag)
	{
		olddir_y = v->dir_y;
		v->dir_y = v->dir_y * cos(-v->rot_speed) - v->dir_x *
		sin(-v->rot_speed);
		v->dir_x = olddir_y * sin(-v->rot_speed) + v->dir_x *
		cos(-v->rot_speed);
		oldplane_y = v->plane_y;
		v->plane_y = v->plane_y * cos(-v->rot_speed) - v->plane_x *
		sin(-v->rot_speed);
		v->plane_x = oldplane_y * sin(-v->rot_speed) + v->plane_x *
		cos(-v->rot_speed);
	}
}

void	flag_left(t_vectors *v, int flag)
{
	double	olddir_y;
	double	oldplane_y;

	if (flag)
	{
		olddir_y = v->dir_y;
		v->dir_y = v->dir_y * cos(v->rot_speed) - v->dir_x *
		sin(v->rot_speed);
		v->dir_x = olddir_y * sin(v->rot_speed) + v->dir_x *
		cos(v->rot_speed);
		oldplane_y = v->plane_y;
		v->plane_y = v->plane_y * cos(v->rot_speed) - v->plane_x *
		sin(v->rot_speed);
		v->plane_x = oldplane_y * sin(v->rot_speed) + v->plane_x *
		cos(v->rot_speed);
	}
}
