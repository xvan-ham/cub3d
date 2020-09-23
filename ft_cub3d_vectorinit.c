/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_vectorinit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:28:51 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/23 20:33:10 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_init_1(t_vectors *v)
{
	v->flag_key_a_down = 0;
	v->flag_key_d_down = 0;
	v->flag_key_left_down = 0;
	v->flag_key_right_down = 0;
	v->flag_key_s_down = 0;
	v->flag_key_w_down = 0;
	v->fov = 0.66;
	v->img = 0;
	v->img_bpp = 0;
	v->img_endian = 0;
	v->img_line_size = 0;
	v->img_ptr = 0;
	v->map = 0;
	v->map_height = 0;
	v->map_width = 0;
	v->map_x = 0;
	v->map_y = 0;
	v->mlx = 0;
	v->orientation = -1;
	v->screen_h = 0;
	v->screen_w = 0;
	v->textures = 0;
	v->wall_dist = 0;
	v->win = 0;
}

static void		ft_init_2(t_vectors *v)
{
	v->camera_y = 0;
	v->delta_dist_x = 0;
	v->delta_dist_y = 0;
	v->dir_x = 0;
	v->dir_y = 0;
	v->hit = 0;
	v->move_speed = 0;
	v->perp_wall_dist = 0;
	v->plane_x = 0;
	v->plane_y = 0;
	v->pos_x = 0;
	v->pos_y = 0;
	v->raydir_x = 0;
	v->raydir_y = 0;
	v->rot_speed = 0;
	v->side = 0;
	v->side_dist_x = 0;
	v->side_dist_y = 0;
	v->step = 0;
	v->step_x = 0;
	v->step_y = 0;
	v->tex_pos = 0;
	v->tex_x = 0;
	v->tex_y = 0;
	v->wall_y = 0;
}

static void		ft_init_3(t_vectors *v)
{
	v->wall_x = 0;
	v->sprite_num = 0;
	v->sprite_order = 0;
	v->sprite_dist = 0;
	v->sprite_info = 0;
	v->sprites = 0;
}

t_sprite_info	*ft_sprite_info_init(void)
{
	t_sprite_info	*s;
	if (!(s = (t_sprite_info *)malloc(sizeof(t_sprite_info))))
		ft_error("Not enough mem for t_sprite_info (malloc)");
	s->transform_x = 0;
	s->transform_y = 0;
	s->sprite_screen_x = 0;
	s->sprite_height = 0;
	s->draw_start_y = 0;
	s->draw_end_y = 0;
	s->sprite_width = 0;
	s->draw_start_x = 0;
	s->draw_end_x = 0;
	s->tex_x = 0;
	s->tex_y = 0;
	s->y = 0;
	s->stripe = 0;
	s->i = 0;
	return (s);
}

void			ft_vectors_initialise(t_vectors *v)
{
	int	i;

	i = 0;
	if (!v)
		ft_error("received null pointer: ft_vectors_initialise");
	ft_init_1(v);
	ft_init_2(v);
	ft_init_3(v);
	if (!(v->sky = (t_color *)malloc(sizeof(t_color))))
		ft_error("Not enough memory for sky color (malloc)");
	if (!(v->floor = (t_color *)malloc(sizeof(t_color))))
		ft_error("Not enough memory for floor color (malloc)");
	if (!(v->textures = malloc(5 * sizeof(t_texture *))))
		ft_error("Not enough memory for texture array (malloc)");
	if (!(v->tex_files = (char **)malloc(sizeof(char *) * 5)))
		ft_error("Not enough memory for tex_files (strings) array (malloc)");
	else
	{
		while (i < 5)
			v->tex_files[i++] = 0;
	}
}
