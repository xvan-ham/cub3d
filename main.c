/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 20:10:45 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/10 20:27:27 by xvan-ham         ###   ########.fr       */
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
	while (i < 3){
		s[i] = s_tex[i];
		i++;
	}
	s[i] = 0; //is this needed? Test
}

void	ft_draw_vert(t_vectors *v, int x, int drawStart, int drawEnd, int tex_n)
{
	int			aux;
	char		*s;
	char		*s_tex;
	t_texture	*t;

	if (!v)
		ft_error("received null pointer: ft_draw_vert");
	t = v->textures[tex_n];
	s_tex = t->img_ptr + (4 * v->tex_y);
	s = v->img_ptr + (x * 4) + (v->img_line_size * drawStart);

	while (drawStart <= drawEnd && (drawEnd - drawStart) > 0)
	{
		v->tex_x = (int)(v->tex_pos);
		if (v->tex_x >= t->tex_h - 1)
			 v->tex_x = t->tex_h - 1;
		ft_color_pixel(s, &s_tex[v->tex_x * t->img_line_size]);
		//ft_memcpy(s, &s_tex[v->tex_x * t->img_line_size], 4);
		s += v->img_line_size;
		v->tex_pos += v->step;
		drawStart++;
	}
}

void	ft_draw_floor(t_vectors *v, int x, int drawEnd)
{
	int				horiz;
	int				bottom;
	char	*s;

	if (!v)
		ft_error("received null pointer: ft_draw_floor");
	bottom = v->screen_h;
	horiz = bottom / 2;
	if (drawEnd > horiz)
		horiz = drawEnd;
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

void	ft_draw_sky(t_vectors *v, int x, int drawStart)
{
	int				horiz;
	unsigned char	*s;

	if (!v)
		ft_error("received null pointer: ft_draw_sky");
	if (!v->img_ptr)
		ft_error("received null pointer: ft_draw_sky (img_ptr)");
	horiz = (v->screen_h) / 2;
	if (horiz > drawStart)
		horiz = drawStart;
	s = (unsigned char *)v->img_ptr;
	s += x * 4 + v->img_line_size;
	while (horiz--)
	{
		s[0] = (v->sky)->b;
		s[1] = (v->sky)->g;
		s[2] = (v->sky)->r;
		s[3] = 0;
		s += v->img_line_size;
	}
}

void	ft_set_move_speed(t_vectors *v)	//TBI: record data at different pixel counts vs fps and find a valid plot
{
	unsigned long int	i;

	if (!v)
		ft_error("received null pointer: ft_set_move_speed");
	i = v->screen_w * v->screen_h;
}

int		ft_choose_wall_texture(t_vectors *v)
{
	if (!v)
		ft_error("received null pointer: ft_choose_wall_texture");
	if (v->side == 0)
	{
		if (v->raydir_y > 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (v->raydir_x > 0)
			return (2);
	}
	return (3);
}

void	ft_raycasting(t_vectors *v)
{
	int		x;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		texNum;

	if (!v)
		ft_error("received null pointer: ft_raycasting");
	printf("ft_raycasting_s: frame: %d\n", v->debug_frame++);
	x = 0;
	while(x < v->screen_w)
    {
     v->camera_y = 2 * x / (double)v->screen_w - 1;
     v->raydir_y = v->dir_y + v->plane_y * v->camera_y;
     v->raydir_x = v->dir_x + v->plane_x * v->camera_y;
     v->map_y = (int)v->pos_y;
     v->map_x = (int)v->pos_x;
      v->delta_dist_y = fabs(1 / v->raydir_y);
      v->delta_dist_x = fabs(1 / v->raydir_x);
      v->hit = 0;
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
      //perform DDA
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
      lineHeight = (int)(v->screen_h / v->perp_wall_dist);
      //calculate lowest and highest pixel to fill in current stripe
      drawStart = -lineHeight / 2 + v->screen_h / 2;
      if(drawStart < 0)
	  	drawStart = 0;
      drawEnd = lineHeight / 2 + v->screen_h / 2;
      if(drawEnd > v->screen_h)
	  	   drawEnd = v->screen_h;
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
	  ft_draw_sky(v, x, drawStart);
	  ft_draw_floor(v, x, drawEnd);
	  ft_draw_vert(v, x, drawStart, drawEnd, texNum);
		x++;
	}
	if (!v)
		ft_error("v is null pointer in: ft_raycasting");
	if (!(v->mlx))
		ft_error("mlx is null pointer in: ft_raycasting");
	if (!(v->win))
		ft_error("mlx is null pointer in: ft_raycasting");
	if (!(v->img))
		ft_error("mlx is null pointer in: ft_raycasting");
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}

int		ft_move(t_vectors *v)
{
	ft_putstr(">");
	if (!v)
		ft_error("received null pointer: ft_move");
	v->flag_stuck = 0;// improve stuck, create another function that checks in all directions
	if (v->flag_key_w_down)
	{
		if(v->map[(int)(v->pos_y + v->dir_y * v->move_speed)][(int)(v->pos_x)] == '0')
			v->pos_y += v->dir_y * v->move_speed;
		if(v->map[(int)(v->pos_y)][(int)(v->pos_x + v->dir_x * v->move_speed)] == '0')
			v->pos_x += v->dir_x * v->move_speed;
		if (v->map[(int)(v->pos_y + v->dir_y * v->move_speed)][(int)(v->pos_x)] ||
			v->map[(int)(v->pos_y)][(int)(v->pos_x + v->dir_x * v->move_speed)])
			v->flag_stuck = 1;

	}
	if (v->flag_key_s_down)
	{
		if(v->map[(int)(v->pos_y - v->dir_y * v->move_speed)][(int)(v->pos_x)] == '0')
			v->pos_y -= v->dir_y * v->move_speed;
		if(v->map[(int)(v->pos_y)][(int)(v->pos_x - v->dir_x * v->move_speed)] == '0')
			v->pos_x -= v->dir_x * v->move_speed;
		if (v->map[(int)(v->pos_y - v->dir_y * v->move_speed)][(int)(v->pos_x)] ||
			v->map[(int)(v->pos_y)][(int)(v->pos_x - v->dir_x * v->move_speed)])
			v->flag_stuck = 1;
	}
	if (v->flag_key_a_down)
	{
		if(v->map[(int)(v->pos_y + v->plane_y * v->move_speed)][(int)(v->pos_x)] =='0')
			v->pos_y -= v->plane_y * v->move_speed;
		if(v->map[(int)(v->pos_y)][(int)(v->pos_x + v->plane_x * v->move_speed)] =='0')
			v->pos_x -= v->plane_x * v->move_speed;
		if (v->map[(int)(v->pos_y + v->plane_y * v->move_speed)][(int)(v->pos_x)] ||
			v->map[(int)(v->pos_y)][(int)(v->pos_x + v->plane_x * v->move_speed)])
			v->flag_stuck = 1;
	}
	if (v->flag_key_d_down)
	{
		if(v->map[(int)(v->pos_y + v->plane_y * v->move_speed)][(int)(v->pos_x)] =='0')
			v->pos_y += v->plane_y * v->move_speed;
		if(v->map[(int)(v->pos_y)][(int)(v->pos_x + v->plane_x * v->move_speed)] =='0')
			v->pos_x += v->plane_x * v->move_speed;
		if (v->map[(int)(v->pos_y + v->plane_y * v->move_speed)][(int)(v->pos_x)] ||
			v->map[(int)(v->pos_y)][(int)(v->pos_x + v->plane_x * v->move_speed)])
			v->flag_stuck = 1;
	}
	if (v->flag_key_right_down)
	{
      //both camera direction and camera plane must be rotated
      double olddir_y = v->dir_y;
      v->dir_y = v->dir_y * cos(-v->rot_speed) - v->dir_x * sin(-v->rot_speed);
      v->dir_x = olddir_y * sin(-v->rot_speed) + v->dir_x * cos(-v->rot_speed);
      double oldplane_y = v->plane_y;
      v->plane_y = v->plane_y * cos(-v->rot_speed) - v->plane_x * sin(-v->rot_speed);
      v->plane_x = oldplane_y * sin(-v->rot_speed) + v->plane_x * cos(-v->rot_speed);
	}
	if (v->flag_key_left_down)
	{
      //both camera direction and camera plane must be rotated
      double olddir_y = v->dir_y;
      v->dir_y = v->dir_y * cos(v->rot_speed) - v->dir_x * sin(v->rot_speed);
      v->dir_x = olddir_y * sin(v->rot_speed) + v->dir_x * cos(v->rot_speed);
      double oldplane_y = v->plane_y;
      v->plane_y = v->plane_y * cos(v->rot_speed) - v->plane_x * sin(v->rot_speed);
      v->plane_x = oldplane_y * sin(v->rot_speed) + v->plane_x * cos(v->rot_speed);
	}
	if (v->flag_stuck)
		ft_putstr("\nSTUCK\n");
	ft_raycasting(v);
	return (0);
}

int		ft_press_key(int key, void *param)
{
	t_vectors	*v;

	v = (t_vectors *)(param);
	if (!v)
		ft_error("received null pointer: ft_press_key");
	if (key == KEY_ESC)
	{
		ft_putstr("\nPressed Esc, closing window - Bye! (FIX me)\n");
		//mlx_destroy_window(v->mlx,v->win);
		exit(0);
	}
	if (key == KEY_W && !v->flag_key_w_down)
		v->flag_key_w_down = 1;
    if(key == KEY_S && !v->flag_key_s_down)
		v->flag_key_s_down = 1;
	if (key == KEY_D && !v->flag_key_d_down)
		v->flag_key_d_down = 1;
	if (key == KEY_A && !v->flag_key_a_down)
		v->flag_key_a_down = 1;
	if(key == KEY_RIGHT && !v->flag_key_right_down)
		v->flag_key_right_down = 1;
    if(key == KEY_LEFT && !v->flag_key_left_down)
		v->flag_key_left_down = 1;
	//ft_putstr("Pressed Key\n");
	return (0);
}

int		ft_release_key(int key, void *param)
{
	t_vectors	*v;

	v = (t_vectors *)(param);
	if (!v)
		ft_error("received null pointer: ft_release_key");
	if (key == KEY_W)
		v->flag_key_w_down = 0;
    if(key == KEY_S)
		v->flag_key_s_down = 0;
    if(key == KEY_D)
		v->flag_key_d_down = 0;
    if(key == KEY_A)
		v->flag_key_a_down = 0;
	if(key == KEY_RIGHT)
		v->flag_key_right_down = 0;
    if(key == KEY_LEFT)
		v->flag_key_left_down = 0;
	//ft_putstr("Released Key\n");
	return (0);
}

int		ft_exit(int key)
{
	ft_putstr("Exiting Cub3D program - Bye!\n");
	exit(0);
}

void	ft_set_hooks(t_vectors *v)
{
	mlx_hook(v->win, 2, 0, ft_press_key, v);
	mlx_hook(v->win, 3, 0, ft_release_key, v);
	mlx_hook(v->win, 17, 0, ft_exit, v);
}

void	ft_set_orientation(t_vectors *v)
{
	if (!v)
		ft_error("received null pointer: ft_set_orientation");
	if (v->orientation == N)
	{
		v->dir_x = 0;
		v->dir_y = -1;
		v->plane_x = v->fov;
		v->plane_y = 0;
	}
	if (v->orientation == E)
	{
		v->dir_x = 1;
		v->dir_y = 0;
		v->plane_x = 0;
		v->plane_y = v->fov;
	}
	if (v->orientation == W)
	{
		v->dir_x = -1;
		v->dir_y = 0;
		v->plane_x = 0;
		v->plane_y = -v->fov;
	}
	if (v->orientation == S)
	{
		v->dir_x = 0;
		v->dir_y = 1;
		v->plane_x = -v->fov;
		v->plane_y = 0;
	}
}

void	ft_raycaster_defaults(t_vectors *v)
{
	t_texture **textures;

	if (!v)
		ft_error("received null pointer: ft_raycaster_defaults");
	v->sky->r = 130;
	v->sky->g = 180;
	v->sky->b = 255;
	v->floor->r = 170;
	v->floor->g = 140;
	v->floor->b = 120;
	v->pos_x = 3; //22
	v->pos_y = 3; //22
	v->screen_h = SH;
	v->screen_w = SW;
	v->rot_speed = PARAM_ROT_SPEED;
	v->move_speed = PARAM_MOV_SPEED;
	printf("ft_raycaster_defaults_e\n");
}

void	ft_load_tex_files(t_vectors *v)
{
	if (!v)
		ft_error("received null pointer: ft_load_tex_files");
	v->tex_files[0] = ft_strdup("../Textures/brick_4.xpm");
	v->tex_files[1] = ft_strdup("../Textures/brick_1.xpm");//bit ugly
	v->tex_files[2] = ft_strdup("../Textures/brick_2.xpm");
	v->tex_files[3] = ft_strdup("../Textures/brick_3.xpm");
}

void	ft_load_textures(t_vectors *v)
{
	t_texture	*tex;
	int			i;
	
	i = 0;
	if (!v)
		ft_error("received null pointer: ft_load_textures");
	ft_load_tex_files(v); //Tested: does not seem to cause segfault
	while (i < 4)
	{
		if (!(tex = /*(t_texture *)*/malloc(sizeof(t_texture))))
			ft_error("Not enough memory for texture (malloc)");
		if (!(tex->img = mlx_xpm_file_to_image(v->mlx, v->tex_files[i], &(tex->tex_w), &(tex->tex_h))))
			ft_error("Could not read texture");  // TBI: send char * of which tex could not be read
		tex->file_name = v->tex_files[i];
		if (!(tex->img_ptr = mlx_get_data_addr(tex->img, &(tex->img_bpp), &(tex->img_line_size),
			&(tex->img_endian))))
			ft_error("Could not get data address from texture img pointer");
		v->textures[i] = tex;
		printf("Loaded texture: %s\n", v->tex_files[i]);
		i++;
	}
	printf("ft_load_textures_e\n");
}

void	ft_mlx_start(t_vectors *v)
{
	if (!v)
		ft_error("received null pointer: ft_mlx_start");
	printf("ft_mlx_start\n");
	ft_vectors_initialise(v);
	ft_raycaster_defaults(v);
	ft_process_cub_file(v);
	ft_set_orientation(v);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->screen_w, v->screen_h, WIN_NAME); //create new WINDOW
	v->img = mlx_new_image(v->mlx, v->screen_w, v->screen_h);
	v->img_ptr = mlx_get_data_addr(v->img, &(v->img_bpp), &(v->img_line_size), &(v->img_endian));
	printf("ft_mlx_start_e: init: mlx, win, img\n");
}

void	ft_cub3d(void)
{
	t_vectors v;

	ft_mlx_start(&v);
	//ft_set_hooks(&v);
	ft_load_textures(&v);
	printf("ft_cub3d: loading hooks\n");
	mlx_hook(v.win, 2, 0, ft_press_key, &v);
	mlx_hook(v.win, 3, 0, ft_release_key, &v);
	mlx_hook(v.win, 17, 0, ft_exit, &v);
	printf("ft_cub3d: loaded hooks, drawing frame\n");
	ft_raycasting(&v);
	printf("ft_cub3d: drawn frame, starting loop hook\n");
	mlx_loop_hook(v.mlx, ft_move, &v);
	//printf("Planned exit for testing purposes\n");
	//exit(0);
	printf("ft_cub3d: done loop hook, next is mlx_loop\n");
	mlx_loop(v.mlx); //EXC_BAD_ACCESS (address= 0x20)
}

int	main (void)//int argc, char **argv)
{
	ft_cub3d();
	//printf("test: <%s>\n", );
	return (0);
}