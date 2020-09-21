/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_sprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:56:34 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/21 20:48:42 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_sort_aux_in_list(int *order, int order_pos, int pos)
{
	int	i;

	i = 0;
	while (i < order_pos)
	{
		if (order[i] == pos)
			return (1);
		i++;
	}
	return (0);
}

static void ft_sort_sprites(t_vectors *v, int* order, double* dist)
{
	double	max;
	int		i;
	int		order_pos;
	int		pos;

	i = 0;
	order_pos = 0;
	pos = 0;
	while (order_pos < v->sprite_num)
	{
		max = -1;
		i = 0;
		pos = i;
		while (i < v->sprite_num)
		{
			if (dist[i] > max && !ft_sort_aux_in_list(order, order_pos, i))
			{
				pos = i;
				max = dist[i];
			}
			i++;
		}
		order[order_pos] = pos;
		order_pos++;
	}
}

static void	ft_order_sprites(t_vectors *v)
{
	
	for(int i = 0; i < v->sprite_num; i++)
    {
      v->sprite_dist[i] = ((v->pos_x - v->sprites[i]->x) * (v->pos_x - v->sprites[i]->x) + (v->pos_y - v->sprites[i]->y) * (v->pos_y - v->sprites[i]->y));
	}
	ft_sort_sprites(v, v->sprite_order, v->sprite_dist);
}

void	ft_raycasting_sprite(t_vectors *v, int tex_n)
{
	t_texture	*t;
	char		*s_tex;
	char		*s;

	t = v->textures[tex_n];
	if (v->sprite_num == 0)
		return ;
	ft_order_sprites(v);
    for(int i = 0; i < v->sprite_num; i++)
    {
      double spriteX = v->sprites[v->sprite_order[i]]->x - v->pos_x;
      double spriteY = v->sprites[v->sprite_order[i]]->y - v->pos_y;
      double invDet = 1.0 / (v->plane_x * v->dir_y - v->dir_x * v->plane_y); //required for correct matrix multiplication
      double transformX = invDet * (v->dir_y * spriteX - v->dir_x * spriteY);
      double transformY = invDet * (- (v->plane_y) * spriteX + v->plane_x * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])
      int spriteScreenX = (int)((v->screen_w / 2) * (1 + transformX / transformY));
      #define uDiv 1
      #define vDiv 1
      #define vMove 0.0
      int vMoveScreen = (int)(vMove / transformY);
      int spriteHeight = abs((int)(v->screen_h / (transformY))) / vDiv; //using "transformY" instead of the real distance prevents fisheye
      int drawStartY = -spriteHeight / 2 + v->screen_h / 2 + vMoveScreen;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + v->screen_h / 2 + vMoveScreen;
      if(drawEndY >= v->screen_h) drawEndY = v->screen_h - 1;
      int spriteWidth = abs((int)(v->screen_h / (transformY))) / uDiv;
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= v->screen_w) drawEndX = v->screen_w - 1;
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * v->textures[4]->tex_w / spriteWidth) / 256;
    	if(transformY > 0 && stripe > 0 && stripe < v->screen_w && transformY < v->wall_dist[stripe])
		{
        for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
        {
          int d = (y - vMoveScreen) * 256 - v->screen_h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
          int texY = ((d * v->textures[4]->tex_h) / spriteHeight) / 256;
		  s = v->img_ptr + (4 * stripe) + v->img_line_size * y;
		  s_tex = t->img_ptr + (4 * texX) + t->img_line_size * texY;
		  if (s_tex[0] && s_tex[1] && s_tex[2])
			  ft_color_pixel(s,s_tex); 
        }
		}
      }
    }
}
