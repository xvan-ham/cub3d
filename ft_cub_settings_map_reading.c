/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_map_reading.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:06:32 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/08 20:04:42 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_getmapstr(const char *c)
{
	int			len;
	const char	*aux;
	char		*str;

	aux = c;
	len = 0;
	while (ft_chars_in_str("012NSWE", c))
	{
		len++;
		c++;
	}
	c = aux;
	if (!(str = (char *)malloc((1 + len) * sizeof(char))))
		ft_error("Malloc for a str in ft_read_map failed");
	aux = str;
	while (*c && ft_strchr(" 012NSEW", *c))
	{
		*(str++) = *(c++);
	}
	*str = 0;
	return ((char *)aux);
}

static void	ft_add_to_tmp_map(t_vectors *v, const char *c, t_str_list **tmp_map)
{
	t_str_list	*element;
	t_str_list	*aux_e;

	if (!(element = ft_str_list_new_element("")))
		ft_error("Malloc for struct t_str_list failed during map reading");
	if (element->str)
		free(element->str);
	element->str = ft_getmapstr(c);
	if (!*tmp_map)
	{
		*tmp_map = element;
		return ;
	}
	aux_e = *tmp_map;
	while (aux_e->next)
		aux_e = aux_e->next;
	aux_e->next = element;
}


void		ft_parse_line(t_vectors *v, const char *c, t_str_list **tmp_map,
	int *flag_map)
{
	char		*debug;

	//ft_check_config(v, c);
	if ((debug = ft_chars_in_str("012NSWE", c)))
	{
		*flag_map = 1;
		ft_add_to_tmp_map(v, c, tmp_map);
		free((void *)c);
		return ;
	}
	else {
		printf("%s\n", debug);
	}
	if (*flag_map)
	{
		ft_error("Invalid map, don't add empty lines to map!!");
		free((void *)c);
	}
}

void		ft_print_tmp_map(t_str_list *tmp_map)
{
	while (tmp_map && tmp_map->next)
	{
		printf("struct str: <%s>\n", tmp_map->str);
		tmp_map = tmp_map->next;
	}
	printf("struct str: <%s>\n", tmp_map->str);
}
