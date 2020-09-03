/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:34:49 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/03 20:41:00 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_str_list	*ft_str_list_new_element(const char *s)
{
	t_str_list	*element;
	char	*str;
	char	*str_s;

	if (!(element = (t_str_list *)malloc(sizeof(t_str_list))))
		return (0);
	element->next = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
		str_s = str;
	while (*s)
		*(str++) = *(s++);
	*str = 0;
	element->str = str_s;
	return (element);
}

void		ft_str_list_delete(t_str_list *element)
{
	t_str_list	*next;

	while ((next = element->next))
	{
		if (element->str)
			free (element->str);
		free (element);
		element = next;
	}
}

static char	*ft_getmapstr(const char *c)
{
	const char	*c_ptr;
	int			len;
	char		*str;
	char		*str_s;

	len = 0;
	c_ptr = c;
	while (*c_ptr && (*c_ptr == ' ' || (*c_ptr >= '0' && *c_ptr <= '2')))
	{
		if (*c_ptr >= '0' && *c_ptr <= '2')
			len++;
		c_ptr++;	
	}
	if (*c_ptr)
		ft_error("Invalid map");
	c_ptr = c;
	if (!(str = (char *)malloc((1 + len) * sizeof(char))))
		ft_error("Malloc for a str in ft_read_map failed");
		str_s = str;
	while (*c_ptr && (*c_ptr == ' ' || (*c_ptr >= '0' && *c_ptr <= '2')))
	{
		while (*c_ptr == ' ')
			c_ptr++;
		*(str++) = *(c_ptr++);
	}
	*str = 0;
	return (str_s);	
}

static void	ft_add_to_tmp_map(t_vectors *v, const char *c, t_str_list **tmp_map)
{
	t_str_list	*element;
	t_str_list	*aux_e;

	if(!(element = ft_str_list_new_element("")))
		ft_error("Malloc for struct t_str_list failed during map reading");
	if (element->str)
		free (element->str);
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

void		ft_parse_line(t_vectors *v, const char *c, t_str_list **tmp_map, int *flag_map)
{
	const char	*c_ptr;
	const char	*start;

	start = 0;
	c_ptr = c;
	while (*c_ptr && (*c_ptr == ' '))
		c_ptr++;
	if (*c_ptr == 0 && *flag_map)
		ft_error("Invalid map, once map info starts don't add spaces nor newlines!!");	
	if (*c_ptr == 0)
		return ;
	if (*c_ptr >= '1' && *c_ptr <= '2')
	{
		*flag_map = 1;
		ft_add_to_tmp_map(v, c_ptr, tmp_map);
		return ;
	}
	free ((void *)c);
	ft_error("Invalid map");	
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

void	ft_process_cub_file(t_vectors *v)
{
    char		*line;
	t_str_list	*tmp_map;
	int			flag_parsing_map;

	flag_parsing_map = 0;
	tmp_map = 0;
	line = 0;
    int fd = open("settings.cub", O_RDONLY);
    int n;
    while ((n = ft_get_next_line(fd, &line)))
    {
		if (line)
		{
			ft_parse_line(v, line, &tmp_map, &flag_parsing_map);
			free(line);
		}
    }
	if (n < 0)
		ft_error("ft_get_next_line returned an error in ft_process_cub_file");
	ft_parse_line(v, line, &tmp_map, &flag_parsing_map);
	free(line);
	//ft_print_tmp_map(tmp_map); //enable to print tmp_map
	
}
