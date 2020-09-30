/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_map_check.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:35:23 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/30 16:37:28 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	return (len + 1);
}

static int	ft_get_map_width(t_vectors *v, t_str_list *tmp_map)
{
	int	max;
	int n;

	if (!v)
		ft_error("received null pointer: ft_check_map_width");
	n = 0;
	max = ft_strlen(tmp_map->str);
	while (tmp_map->next)
	{
		tmp_map = tmp_map->next;
		n = ft_strlen(tmp_map->str);
		if (n > max)
			max = n;
	}
	return (max);
}

void		ft_check_map(t_vectors *v, t_str_list *tmp_map)
{
	if (!v)
		ft_error("received null pointer: ft_check_map");
	v->map_height = ft_get_map_height(v, tmp_map);
	v->map_width = ft_get_map_width(v, tmp_map);
}
