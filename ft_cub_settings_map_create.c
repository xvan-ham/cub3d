/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_map_create.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:16:15 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/10 17:43:32 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_print_map(t_vectors *v, char **map)
{
	if (!v || !map)
		ft_error("null pointer passed to ft_print_map");
	int r, c, i, j;
	r = v->map_height;
	c = v->map_width;
    for (i = 0; i <  r; i++) 
    {
		for (j = 0; j < c; j++) 
         printf("%c ", map[i][j]);
        printf("\n");
	}
}

static void	ft_create_matrix(t_vectors *v)
{
	int	i;
	int	j;
  
    char **map = (char **)malloc(v->map_height * sizeof(char *)); 
	i = 0;
	while (i < v->map_height)
         map[i++] = (char *)malloc(v->map_width * sizeof(char)); 
    // Note that arr[i][j] is same as *(*(arr+i)+j)
	i = 0; 
	j = 0;
	while (i < v->map_height)
	{
		while (j < v->map_width)
        	map[i][j++] = 'X';  // OR *(*(arr+i)+j) = ++count
		j = 0; 
		i++;
	}
	ft_print_map(v, map);
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
        		v->map[i][j] = (ft_str_list_get_element(tmp_map, i)->str)[j];  // OR *(*(arr+i)+j) = ++count
			j++;
		}
		j = 0; 
		i++;
	}
}

void	ft_create_map(t_vectors *v, t_str_list *tmp_map)
{
	ft_create_matrix(v);
	ft_copy_map(v, tmp_map);
	printf("\n\n");
	ft_print_map(v, v->map);

}
