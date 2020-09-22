/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_sprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:56:34 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/22 20:23:43 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_transform_params(t_vectors *v, t_sprite_info *spr)
{
	spr->transform_x = (1.0 / (v->plane_x * v->dir_y - v->dir_x * v->plane_y))
	* (v->dir_y * (v->sprites[v->sprite_order[spr->i]]->x - v->pos_x) -
	v->dir_x * (v->sprites[v->sprite_order[spr->i]]->y - v->pos_y));
	spr->transform_y = (1.0 / (v->plane_x * v->dir_y - v->dir_x * v->plane_y)) *
	(-(v->plane_y) * (v->sprites[v->sprite_order[spr->i]]->x - v->pos_x) +
	v->plane_x * (v->sprites[v->sprite_order[spr->i]]->y - v->pos_y));
	spr->sprite_screen_x = (int)((v->screen_w / 2) *
		(1 + spr->transform_x / spr->transform_y));
	spr->sprite_height = abs((int)(v->screen_h / (spr->transform_y)));
	spr->draw_start_y = -spr->sprite_height / 2 + v->screen_h / 2;
	if (spr->draw_start_y < 0)
		spr->draw_start_y = 0;
	spr->draw_end_y = spr->sprite_height / 2 + v->screen_h / 2;
	if (spr->draw_end_y >= v->screen_h)
		spr->draw_end_y = v->screen_h - 1;
	spr->sprite_width = abs((int)(v->screen_h / (spr->transform_y)));
	spr->draw_start_x = -spr->sprite_width / 2 + spr->sprite_screen_x;
	if (spr->draw_start_x < 0)
		spr->draw_start_x = 0;
	spr->draw_end_x = spr->sprite_width / 2 + spr->sprite_screen_x;
	if (spr->draw_end_x >= v->screen_w)
		spr->draw_end_x = v->screen_w - 1;
	spr->stripe = spr->draw_start_x;
}

static void	ft_cycle_vert_pixels(t_vectors *v, t_sprite_info *spr, int tex_n)
{
	char		*s_tex;
	char		*s;
	t_texture	*t;

	t = v->textures[tex_n];
	spr->tex_y = (((spr->y * 256 - v->screen_h * 128 + spr->sprite_height * 128)
		* v->textures[4]->tex_h) / spr->sprite_height) / 256;
	s = v->img_ptr + (4 * spr->stripe) + v->img_line_size * spr->y;
	s_tex = t->img_ptr + (4 * spr->tex_x) + t->img_line_size * spr->tex_y;
	if (s_tex[0] && s_tex[1] && s_tex[2])
		ft_color_pixel(s, s_tex);
	spr->y++;
}

void		ft_raycasting_sprite(t_vectors *v, int tex_n)
{
	t_sprite_info	*spr;

	spr = v->sprite_info;
	ft_order_sprites(v);
	spr->i = 0;
	while (spr->i < v->sprite_num)
	{
		ft_set_transform_params(v, spr);
		while (spr->stripe < spr->draw_end_x)
		{
			spr->tex_x = (int)(256 * (spr->stripe - (-spr->sprite_width / 2 +
				spr->sprite_screen_x)) * v->textures[4]->tex_w /
				spr->sprite_width) / 256;
			if (spr->transform_y > 0 && spr->stripe > 0 && spr->stripe <
				v->screen_w && spr->transform_y < v->wall_dist[spr->stripe])
			{
				spr->y = spr->draw_start_y;
				while (spr->y < spr->draw_end_y)
					ft_cycle_vert_pixels(v, spr, tex_n);
			}
			spr->stripe++;
		}
		spr->i++;
	}
}
