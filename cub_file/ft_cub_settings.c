/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:34:49 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/14 19:25:52 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>


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
			ft_parse_line(v, line, &tmp_map, &flag_parsing_map);
    }
	if (n < 0)
		ft_error("ft_get_next_line returned an error in ft_process_cub_file");
	ft_parse_line(v, line, &tmp_map, &flag_parsing_map);
	ft_print_tmp_map(tmp_map); //enable to print tmp_map
	ft_check_map(v, tmp_map);
	ft_create_map(v, tmp_map);
	ft_load_player_position(v);
	ft_floodcheck(v, v->pos_x, v->pos_y);
	ft_str_list_delete(tmp_map);
}
