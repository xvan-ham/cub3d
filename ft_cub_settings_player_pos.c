/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_player_pos.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 19:50:07 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/10 20:28:20 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_orientation(t_vectors *v, char c)
{
	if (c == 'N')
		v->orientation = N;
	if (c == 'S')
		v->orientation = S;
	if (c == 'W')
		v->orientation = W;
	if (c == 'E')
		v->orientation = E;
}

void	ft_load_player_position(t_vectors *v)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	v->pos_x = 5;//rm after fixing
	v->pos_y = 5;//rm after fixing
	v->orientation = S;//rm after fixing
	return ;//rm after fixing
	while (y < v->map_height)
	{
		while (x < v->map_width)
		{
			if (ft_strchr("NSWE",v->map[y][x++]))
			{
				printf("Setting orient.: <%c>; Pos: x:<%d>; y:<%d>\n", v->map[y][x - 1], x - 1, y);
				ft_set_orientation(v, v->map[y][x - 1]);
				v->pos_x = x - 1;
				v->pos_y = y;
				return ;
			}
		}
		x = 0; 
		y++;
	}
}