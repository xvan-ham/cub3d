/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_map_create.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:16:15 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/22 19:14:09 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		ft_print_map(t_vectors *v, char **map)
{
	int r;
	int c;
	int x;
	int y;

	if (!v || !map)
		ft_error("null pointer passed to ft_print_map");
	r = v->map_height;
	c = v->map_width;
	y = 0;
	while (y < v->map_height)
	{
		x = 0;
		while (x < v->map_width)
			write(1, &map[y][x++], 1);
		write(1, "\n", 1);
		y++;
	}
}

static void	ft_create_matrix(t_vectors *v)
{
	int		i;
	int		j;
	char	**map;

	map = (char **)malloc(v->map_height * sizeof(char *));
	i = 0;
	while (i < v->map_height)
		map[i++] = (char *)malloc(v->map_width * sizeof(char));
	i = 0;
	j = 0;
	while (i < v->map_height)
	{
		while (j < v->map_width)
			map[i][j++] = 'X';
		j = 0;
		i++;
	}
	if (PRINT_MAPS)
	{
		write(1, "\n", 1);
		ft_print_map(v, map);
	}
	v->map = map;
}

static void	ft_copy_map(t_vectors *v, t_str_list *tmp_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < v->map_height)
	{
		while (j < v->map_width)
		{
			if (!(ft_str_list_get_element(tmp_map, i)->str)[j])
				break ;
			if ((ft_str_list_get_element(tmp_map, i)->str)[j] != ' ')
				v->map[i][j] = (ft_str_list_get_element(tmp_map, i)->str)[j];
			j++;
		}
		j = 0;
		i++;
	}
}

void		ft_create_map(t_vectors *v, t_str_list *tmp_map)
{
	ft_create_matrix(v);
	ft_copy_map(v, tmp_map);
	if (PRINT_MAPS)
	{
		ft_putstr("\n");
		ft_print_map(v, v->map);
	}
}
