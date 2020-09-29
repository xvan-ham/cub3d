/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_map_floodcheck.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:34:04 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/28 19:55:46 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_add_sprite(t_vectors *v, int x, int y)
{
	int	i;

	i = 0;
	while (v->sprites[i] != 0)
		i++;
	v->sprites[i] = ft_new_sprite(x, y);
}

static void	ft_flood_refill(t_vectors *v, char **map, int x, int y)
{
	if (x < 0 || x > v->map_width - 1 || y < 0 || y > v->map_height - 1)
		return ;
	if (ft_strchr("ZY", map[y][x]))
	{
		if (map[y][x] == 'Y')
			map[y][x] = '2';
		else
			map[y][x] = '0';
		ft_flood_refill(v, map, x + 1, y);
		ft_flood_refill(v, map, x - 1, y);
		ft_flood_refill(v, map, x, y + 1);
		ft_flood_refill(v, map, x, y - 1);
	}
}

static void	ft_flood_fill(t_vectors *v, char **map, int x, int y)
{
	if (x < 0 || x > v->map_width - 1 || y < 0 || y > v->map_height - 1)
		return ;
	if (ft_strchr("02NSWE", map[y][x]))
	{
		if (!x || !y || x >= v->map_width - 1 || y >= v->map_height - 1)
			ft_error("Map leak!");
		if (map[y][x] == '2')
		{
			map[y][x] = 'Y';
			ft_add_sprite(v, x, y);
		}
		else
			map[y][x] = 'Z';
		ft_flood_fill(v, map, x + 1, y);
		ft_flood_fill(v, map, x - 1, y);
		ft_flood_fill(v, map, x, y + 1);
		ft_flood_fill(v, map, x, y - 1);
	}
	if (map[y][x] == 'X')
		ft_error("Map leak!");
}

void		ft_floodcheck(t_vectors *v, int pos_x, int pos_y)
{
	ft_flood_fill(v, v->map, pos_x, pos_y);
	if (PRINT_MAPS)
	{
		write(1, "\n", 1);
		ft_print_map(v, v->map);
		write(1, "\n", 1);
	}
	ft_flood_refill(v, v->map, pos_x, pos_y);
	if (PRINT_MAPS)
	{
		ft_print_map(v, v->map);
		write(1, "\n", 1);
	}
}
