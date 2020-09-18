/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_sprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:56:34 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/18 20:02:46 by xvan-ham         ###   ########.fr       */
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

static void ft_sort_sprites(t_vectors *v, int* order, double* dist, int amount)
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
	ft_sort_sprites(v, v->sprite_order, v->sprite_dist, v->sprite_num);
}

void	ft_raycasting_sprite(t_vectors *v)
{
	if (v->sprite_num == 0)
		return ;
	ft_order_sprites(v);
    //after sorting the sprites, do the projection and draw them
    for(int i = 0; i < v->sprite_num; i++)
    {
      //translate sprite position to relative to camera
      double spriteX = v->sprites[v->sprite_order[i]]->x - v->pos_x;
      double spriteY = v->sprites[v->sprite_order[i]]->y - v->pos_y;

      //transform sprite with the inverse camera matrix
      // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
      // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
      // [ planeY   dirY ]                                          [ -planeY  planeX ]

      double invDet = 1.0 / (v->plane_x * v->dir_y - v->dir_x * v->plane_y); //required for correct matrix multiplication

      double transformX = invDet * (v->dir_y * spriteX - v->dir_x * spriteY);
      double transformY = invDet * (- (v->plane_y) * spriteX + v->plane_y * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])

      int spriteScreenX = (int)((v->screen_w / 2) * (1 + transformX / transformY));

      //parameters for scaling and moving the sprites
      #define uDiv 1
      #define vDiv 1
      #define vMove 0.0
      int vMoveScreen = (int)(vMove / transformY);

      //calculate height of the sprite on screen
      int spriteHeight = abs((int)(v->screen_h / (transformY))) / vDiv; //using "transformY" instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
      int drawStartY = -spriteHeight / 2 + v->screen_h / 2 + vMoveScreen;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + v->screen_h / 2 + vMoveScreen;
      if(drawEndY >= v->screen_h) drawEndY = v->screen_h - 1;

      //calculate width of the sprite
      int spriteWidth = abs((int)(v->screen_h / (transformY))) / uDiv;
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= v->screen_w) drawEndX = v->screen_w - 1;

      //loop through every vertical stripe of the sprite on screen
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        //int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * v->textures[4]->tex_w / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
		v->x = stripe;
    	//if(transformY > 0 && stripe > 0 && stripe < v->screen_w && transformY < v->wall_dist[stripe])
		//	ft_draw_vert(v, drawStartY, drawEndY, 4);
		/*
        for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
        {
          int d = (y-vMoveScreen) * 256 - v->screen_h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
          int texY = ((d * v->textures[4]->tex_h) / spriteHeight) / 256;
          Uint32 color = texture[sprite[spriteOrder[i]].texture][v->textures[4]->tex_w * texY + texX]; //get current color from the texture
          if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
        }*/
      }
    }
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}
