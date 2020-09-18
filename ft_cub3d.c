/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:09:03 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/18 17:36:01 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_exit(int key)
{
	ft_putstr("Exiting Cub3D program - Bye!\n");
	exit(0);
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
	v->screen_h = SH;
	v->screen_w = SW;
	v->rot_speed = PARAM_ROT_SPEED;
	v->move_speed = PARAM_MOV_SPEED;
	printf("ft_raycaster_defaults_e\n");
}

void	ft_mlx_start(t_vectors *v)
{
	if (!v)
		ft_error("received null pointer: ft_mlx_start");
	printf("ft_mlx_start\n");
	ft_vectors_initialise(v);
	ft_raycaster_defaults(v);
	ft_process_cub_file(v);
	ft_set_orientation_params(v);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->screen_w, v->screen_h, WIN_NAME);
	v->img = mlx_new_image(v->mlx, v->screen_w, v->screen_h);
	v->img_ptr = mlx_get_data_addr(v->img, &(v->img_bpp),
				&(v->img_line_size), &(v->img_endian));
	printf("ft_mlx_start_e: init: mlx, win, img\n");
}

void	ft_cub3d(void)
{
	t_vectors v;

	ft_mlx_start(&v);
	ft_load_textures(&v);
	printf("ft_cub3d: loading hooks\n");
	mlx_hook(v.win, 2, 0, ft_press_key, &v);
	mlx_hook(v.win, 3, 0, ft_release_key, &v);
	mlx_hook(v.win, 17, 0, ft_exit, &v);
	printf("Total Sprites: <%d>\n", v.sprite_num);
	printf("ft_cub3d: loaded hooks, drawing frame\n");
	ft_raycasting(&v);
	printf("ft_cub3d: drawn frame, starting loop hook\n");
	mlx_loop_hook(v.mlx, ft_move, &v);
	printf("ft_cub3d: done loop hook, next is mlx_loop\n");
	mlx_loop(v.mlx);
}
