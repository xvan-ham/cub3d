/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 20:01:16 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/14 20:39:32 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_param_calc(t_vectors *v, int x)
{
	if (!v)
		ft_error("received null pointer: ft_raycasting");
	v->camera_y = 2 * x / (double)v->screen_w - 1;
	v->raydir_y = v->dir_y + v->plane_y * v->camera_y;
	v->raydir_x = v->dir_x + v->plane_x * v->camera_y;
	v->map_y = (int)v->pos_y;
	v->map_x = (int)v->pos_x;
	v->delta_dist_y = fabs(1 / v->raydir_y);
	v->delta_dist_x = fabs(1 / v->raydir_x);
	v->hit = 0;
}

void	ft_sec_param_calc(t_vectors *v, int x)
{
	if(v->raydir_y < 0)
	{
		v->step_y = -1;
		v->side_dist_y = (v->pos_y - v->map_y) * v->delta_dist_y;
	}
	else
	{
		v->step_y = 1;
		v->side_dist_y = (v->map_y + 1.0 - v->pos_y) * v->delta_dist_y;
	}
	if(v->raydir_x < 0)
	{
		v->step_x = -1;
		v->side_dist_x = (v->pos_x - v->map_x) * v->delta_dist_x;
	}
	else
	{
		v->step_x = 1;
		v->side_dist_x = (v->map_x + 1.0 - v->pos_x) * v->delta_dist_x;
	}
}

void	ft_dda(t_vectors *v, int x, int *lineHeight)
{
      while (v->hit == 0)
      {
        if(v->side_dist_y < v->side_dist_x)
        {
          v->side_dist_y += v->delta_dist_y;
          v->map_y += v->step_y;
          v->side = 0;
        }
        else
        {
          v->side_dist_x += v->delta_dist_x;
          v->map_x += v->step_x;
          v->side = 1;
        }
        if(v->map[v->map_y][v->map_x] > '0' && v->map[v->map_y][v->map_x] <= '2')
			v->hit = 1;
      }
      if(v->side == 0)
	  	v->perp_wall_dist = (v->map_y - v->pos_y + (1 - v->step_y) / 2) / v->raydir_y;
      else
	  	v->perp_wall_dist = (v->map_x - v->pos_x + (1 - v->step_x) / 2) / v->raydir_x;
      *lineHeight = (int)(v->screen_h / v->perp_wall_dist);
}

int	ft_set_draw_and_tex_params(t_vectors *v, int x, int lineHeight, int drawStart)
{
	int		texNum;
	
	  texNum = ft_choose_wall_texture(v);
      if(v->side == 0)
	  	v->wall_y = v->pos_x + v->perp_wall_dist * v->raydir_x;
      else
	  	v->wall_y = v->pos_y + v->perp_wall_dist * v->raydir_y;
      v->wall_y -= (double)((int)v->wall_y);
      v->tex_y = (int)(v->wall_y * (double)((v->textures[texNum])->tex_w));
      if(v->side == 0 && v->raydir_y > 0)
	  	v->tex_y = (v->textures[texNum])->tex_w - v->tex_y - 1;
      if(v->side == 1 && v->raydir_x < 0)
	  	v->tex_y = (v->textures[texNum])->tex_w - v->tex_y - 1;
      v->step = 1.0 * (v->textures[texNum])->tex_h / lineHeight;
      v->tex_pos = (drawStart - v->screen_h / 2 + lineHeight / 2) * v->step;
	  return (texNum);
}

void	ft_raycasting(t_vectors *v)
{
	int		x;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		texNum;

	x = 0;
	while(x < v->screen_w)
	{
		ft_init_param_calc(v, x);
		ft_sec_param_calc(v, x);
		ft_dda(v, x, &lineHeight);
	drawStart = -lineHeight / 2 + v->screen_h / 2;
      if(drawStart < 0)
	  	drawStart = 0;
      drawEnd = lineHeight / 2 + v->screen_h / 2;
      if(drawEnd > v->screen_h)
	  	   drawEnd = v->screen_h;
		texNum = ft_set_draw_and_tex_params(v, x, lineHeight, drawStart);
	  ft_draw_sky(v, x, drawStart);
	  ft_draw_floor(v, x, drawEnd);
	  ft_draw_vert(v, x, drawStart, drawEnd, texNum);
		x++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}
