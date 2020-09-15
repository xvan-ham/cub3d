/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_player_pos.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 19:50:07 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/15 18:37:09 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_set_orientation(t_vectors *v, char c)
{
	if (v->orientation >= 0)
		ft_error("Map has more than one specified spawn location");
	if (c == 'N')
		v->orientation = N;
	if (c == 'S')
		v->orientation = S;
	if (c == 'W')
		v->orientation = W;
	if (c == 'E')
		v->orientation = E;
}

void		ft_load_player_position(t_vectors *v)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < v->map_height)
	{
		while (x < v->map_width)
		{
			if (ft_strchr("NSWE", v->map[y][x++]))
			{
				ft_set_orientation(v, v->map[y][x - 1]);
				v->pos_x = x - 0.5;
				v->pos_y = y + 0.5;
			}
		}
		x = 0;
		y++;
	}
	if (v->orientation < 0)
		ft_error("Map has no specified spawn location");
}
