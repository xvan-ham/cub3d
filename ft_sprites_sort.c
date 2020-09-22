/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:49:04 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/22 16:27:37 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_sort_aux_in_list(int *order, int order_pos, int pos)
{
	int	i;

	i = 0;
	while (i < order_pos)
	{
		if (order[i] == pos)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_sort_sprites(t_vectors *v, int *order, double *dist)
{
	double	max;
	int		i;
	int		order_pos;
	int		pos;

	i = 0;
	order_pos = 0;
	pos = 0;
	while (order_pos < v->sprite_num)
	{
		max = -1;
		i = 0;
		pos = i;
		while (i < v->sprite_num)
		{
			if (dist[i] > max && !ft_sort_aux_in_list(order, order_pos, i))
			{
				pos = i;
				max = dist[i];
			}
			i++;
		}
		order[order_pos] = pos;
		order_pos++;
	}
}

void		ft_order_sprites(t_vectors *v)
{
	int	i;

	i = 0;
	while (i < v->sprite_num)
	{
		v->sprite_dist[i] = ((v->pos_x - v->sprites[i]->x) *
		(v->pos_x - v->sprites[i]->x) + (v->pos_y - v->sprites[i]->y) *
		(v->pos_y - v->sprites[i]->y));
		i++;
	}
	ft_sort_sprites(v, v->sprite_order, v->sprite_dist);
	i++;
}
