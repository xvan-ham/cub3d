/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:34:49 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/30 16:37:32 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_check_print(int flag, t_str_list *tmp_map)
{
	if (flag)
		ft_print_tmp_map(tmp_map);
}

static void	ft_error_check(t_vectors *v, int n)
{
	if (n < 0)
		ft_error("ft_get_next_line returned an error in ft_process_cub_file");
	if (!(v->wall_dist = malloc(v->screen_w * sizeof(double))))
		ft_error("Not enough memory for double array <wall_dist> (malloc)");
}

static void	ft_allocate_sprite_arrays(t_vectors *v)
{
	int	i;

	i = 0;
	if (v->sprite_num > 0)
	{
		if (!(v->sprite_order = malloc(v->sprite_num * sizeof(int))))
			ft_error("Not enough memory for int array <sprite_order> (malloc)");
		if (!(v->sprite_dist = malloc(v->sprite_num * sizeof(double))))
			ft_error("Not enough mem. for malloc of <sprite_distance>");
		if (!(v->sprites = malloc(v->sprite_num * sizeof(t_sprite *))))
			ft_error("Not enough memory for sprite array (malloc)");
		while (i < v->sprite_num)
			v->sprites[i++] = 0;
	}
}

static void	ft_map_checks(t_vectors *v, t_str_list *tmp_map)
{
	if (!tmp_map)
		ft_error("There is no map present in the cub file.");
	ft_check_print(PRINT_MAPS, tmp_map);
	ft_check_map(v, tmp_map);
	ft_create_map(v, tmp_map);
	ft_load_player_position(v);
	ft_allocate_sprite_arrays(v);
	ft_floodcheck(v, v->pos_x, v->pos_y);
	ft_str_list_delete(tmp_map);
}

void		ft_process_cub_file(t_vectors *v, const char *cub_file)
{
	char		*line;
	t_str_list	*tmp_map;
	int			flag_parsing_map;
	int			fd;
	int			n;

	flag_parsing_map = 0;
	tmp_map = 0;
	line = 0;
	fd = open(cub_file, O_RDONLY);
	if (fd == -1)
		ft_error("Could not find the specified cub file.");
	while ((n = ft_get_next_line(fd, &line)))
	{
		if (line)
			ft_parse_line(v, line, &tmp_map, &flag_parsing_map);
	}
	ft_error_check(v, n);
	if (ft_strlen(line) > 0)
		ft_parse_line(v, line, &tmp_map, &flag_parsing_map);
	close(fd);
	ft_map_checks(v, tmp_map);
}
