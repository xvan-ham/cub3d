/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_map_check.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:35:23 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/07 20:39:09 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_map_height(t_vectors *v, t_str_list *tmp_map)
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
	return(len + 1);
}

static int	ft_check_map_width(t_vectors *v, t_str_list *tmp_map)
{
	int	max; //interrupted day here, continue here!!

	if (!v)
		ft_error("received null pointer: ft_check_map_width");
	max = 0;
	//max = ft_strlen();
	while (tmp_map->next)
	{

		tmp_map = tmp_map->next;
		max++;
	}
	return(max + 1);
}

void	ft_check_map(t_vectors *v, t_str_list *tmp_map)
{
	int	len;

	if (!v)
		ft_error("received null pointer: ft_check_map");
	len = 0;
	while (tmp_map->next)
	{
		tmp_map = tmp_map->next;
		len++;
	}
	v->map_height = len + 1;
}
