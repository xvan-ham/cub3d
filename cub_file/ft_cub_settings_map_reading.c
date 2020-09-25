/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings_map_reading.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:06:32 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/25 19:18:39 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	ft_count_sprites(const char *s)
{
	int sprites;

	sprites = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '2')
			sprites++;
		s++;
	}
	return (sprites);
}

static char	*ft_getmapstr(const char *c)
{
	int			len;
	const char	*aux;
	char		*str;

	aux = c;
	len = 0;
	while (ft_chars_in_str("012NSWE", c))
	{
		if (!ft_strchr(" 012NSWE", *c))
			ft_error("Illegal character(s) in map");
		len++;
		c++;
	}
	c = aux;
	if (!(str = (char *)malloc((1 + len) * sizeof(char))))
		ft_error("Malloc for a str in ft_read_map failed");
	aux = str;
	while (len-- && ft_strchr(" 012NSEW", *c))
	{
		*(str++) = *(c++);
	}
	*str = 0;
	ft_print_cond((char *)aux, PRINT_MAPS);
	return ((char *)aux);
}

void		ft_add_to_tmp_map(t_vectors *v, const char *c, t_str_list **tmp_map)
{
	t_str_list	*element;
	t_str_list	*aux_e;

	if (!(element = ft_str_list_new_element("")))
		ft_error("Malloc for struct t_str_list failed during map reading");
	if (element->str)
		free(element->str);
	element->str = ft_getmapstr(c);
	v->sprite_num += ft_count_sprites(element->str);
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

void		ft_print_tmp_map(t_str_list *tmp_map)
{
	ft_putstr("\n");
	while (tmp_map && tmp_map->next)
	{
		ft_putstr("struct str: ");
		ft_putstr(tmp_map->str);
		ft_putstr("\n");
		tmp_map = tmp_map->next;
	}
	ft_putstr("struct str: ");
	ft_putstr(tmp_map->str);
	ft_putstr("\n");
}
