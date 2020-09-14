/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_get_map_params.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:35:23 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/14 13:27:18 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood.h"

static int	ft_get_map_height(t_vectors *v, t_str_list *tmp_map)
{
	int	len;

	if (!v)
		ft_error("received null pointer: ft_check_map_height");
	len = 0;
	while (tmp_map->next)
	{
		tmp_map = tmp_map->next;
		len++;
	}
	if (len + 1 > MAPHEIGHT_LIM)
		ft_error("Input map is too big. Descrease or change lim.");
	return(len + 1);
}

static int	ft_get_map_width(t_vectors *v, t_str_list *tmp_map)
{
	int	max; //interrupted day here, continue here!!
	int n;

	if (!v)
		ft_error("received null pointer: ft_check_map_width");
	n = 0;
	max = ft_strlen(tmp_map->str); //for the first string sometimes the size is too big!
	while (tmp_map->next)
	{
		//printf("max: <%d>; str: <%s>\n", max, tmp_map->str);
		tmp_map = tmp_map->next;
		n = ft_strlen(tmp_map->str);
		if (n > max)
			max = n;
	}
	if (max > MAPWIDTH_LIM)
		ft_error("Input map is too big. Descrease or change lim.");
	return(max);
}

static void	ft_precheck_map(t_str_list *tmp_map)
{
	int	y;
	int	x;

	y = 0; 
	x = 0;
	while (ft_str_list_get_element(tmp_map, y))
	{
		while ((ft_str_list_get_element(tmp_map, y)->str)[x])
		{
			if (!ft_strchr(" 012NSWE", (ft_str_list_get_element(tmp_map, y)->str)[x]))
                ft_error("Illegal character(s) in map"); 
			x++;
		}
		x = 0; 
		y++;
    }
}

void	ft_check_map(t_vectors *v, t_str_list *tmp_map) //TBI: Add map validation
{
	int	len;

	if (!v)
		ft_error("received null pointer: ft_check_map");
	//ft_precheck_map(tmp_map);
	v->map_height = ft_get_map_height(v, tmp_map);
	v->map_width = ft_get_map_width(v, tmp_map);
	printf("Height: %d, Width: %d\n", v->map_height, v->map_width);
}
