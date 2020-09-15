/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:18:29 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/15 17:21:27 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_orientation_ns(t_vectors *v)
{
	if (v->orientation == N)
	{
		v->dir_x = 0;
		v->dir_y = -1;
		v->plane_x = v->fov;
		v->plane_y = 0;
	}
	if (v->orientation == S)
	{
		v->dir_x = 0;
		v->dir_y = 1;
		v->plane_x = -v->fov;
		v->plane_y = 0;
	}
}

void		ft_set_orientation_params(t_vectors *v)
{
	if (!v)
		ft_error("received null pointer: ft_set_orientation_params");
	ft_orientation_ns(v);
	if (v->orientation == E)
	{
		v->dir_x = 1;
		v->dir_y = 0;
		v->plane_x = 0;
		v->plane_y = v->fov;
	}
	if (v->orientation == W)
	{
		v->dir_x = -1;
		v->dir_y = 0;
		v->plane_x = 0;
		v->plane_y = -v->fov;
	}
}
