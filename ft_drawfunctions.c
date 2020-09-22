/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:52:48 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/22 18:25:55 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_color_pixel(char *s, char *s_tex)
{
	int	i;

	if (!s)
		ft_error("received null pointer: ft_color_pixel (img ptr)");
	if (!s_tex)
		ft_error("received null pointer: ft_color_pixel (tex pixel ptr)");
	i = 0;
	while (i < 3)
	{
		s[i] = s_tex[i];
		i++;
	}
	s[i] = 0;
}

void	ft_draw_vert(t_vectors *v, int draw_start, int draw_end, int tex_n)
{
	char		*s;
	char		*s_tex;
	t_texture	*t;
	int			x;

	if (!v)
		ft_error("received null pointer: ft_draw_vert");
	x = v->x;
	t = v->textures[tex_n];
	s_tex = t->img_ptr + (4 * v->tex_y);
	s = v->img_ptr + (x * 4) + (v->img_line_size * draw_start);
	while (draw_start <= draw_end && (draw_end - draw_start) > 0)
	{
		v->tex_x = (int)(v->tex_pos);
		if (v->tex_x >= t->tex_h - 1)
			v->tex_x = t->tex_h - 1;
		ft_color_pixel(s, &s_tex[v->tex_x * t->img_line_size]);
		s += v->img_line_size;
		v->tex_pos += v->step;
		draw_start++;
	}
}

void	ft_draw_floor(t_vectors *v, int x, int draw_end)
{
	int				horiz;
	int				bottom;
	char			*s;

	if (!v)
		ft_error("received null pointer: ft_draw_floor");
	bottom = v->screen_h;
	horiz = bottom / 2;
	if (draw_end > horiz)
		horiz = draw_end;
	s = v->img_ptr;
	s += x * 4 + v->img_line_size * horiz;
	while (horiz <= bottom - 1)
	{
		s[0] = (v->floor)->b;
		s[1] = (v->floor)->g;
		s[2] = (v->floor)->r;
		s[3] = 0;
		s += v->img_line_size;
		horiz++;
	}
}

void	ft_draw_sky(t_vectors *v, int x, int draw_start)
{
	int				horiz;
	unsigned char	*s;

	if (!v)
		ft_error("received null pointer: ft_draw_sky");
	if (!v->img_ptr)
		ft_error("received null pointer: ft_draw_sky (img_ptr)");
	horiz = (v->screen_h) / 2;
	if (horiz > draw_start)
		horiz = draw_start;
	s = (unsigned char *)v->img_ptr;
	s += x * 4;
	while (horiz-- >= 0)
	{
		s[0] = (v->sky)->b;
		s[1] = (v->sky)->g;
		s[2] = (v->sky)->r;
		s[3] = 0;
		s += v->img_line_size;
	}
}
