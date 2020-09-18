/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:10:34 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/18 20:22:54 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	ft_load_tex_files(t_vectors *v)
{
	if (!v)
		ft_error("received null pointer: ft_load_tex_files");
	if (v->tex_files[0] == 0)
		v->tex_files[0] = ft_strdup("./Textures/brick_4.xpm");
	if (v->tex_files[1] == 0)
		v->tex_files[1] = ft_strdup("./Textures/brick_1.xpm");
	if (v->tex_files[2] == 0)
		v->tex_files[2] = ft_strdup("./Textures/brick_2.xpm");
	if (v->tex_files[3] == 0)
		v->tex_files[3] = ft_strdup("./Textures/brick_3.xpm");
	if (v->tex_files[4] == 0 && v->sprite_num)
		v->tex_files[4] = ft_strdup("./Textures/barrel.xpm");
}

void	ft_load_textures(t_vectors *v)
{
	t_texture	*tex;
	int			i;

	i = 0;
	if (!v)
		ft_error("received null pointer: ft_load_textures");
	ft_load_tex_files(v);
	while (i < (v->sprite_num > 0 ? 5 : 4))
	{
		if (!(tex = malloc(sizeof(t_texture))))
			ft_error("Not enough memory for texture (malloc)");
		if (!(tex->img = mlx_xpm_file_to_image(v->mlx, v->tex_files[i],
			&(tex->tex_w), &(tex->tex_h))))
			ft_error("Could not read texture");
		//tex->file_name = v->tex_files[i];
		if (!(tex->img_ptr = mlx_get_data_addr(tex->img,
		&(tex->img_bpp), &(tex->img_line_size),
			&(tex->img_endian))))
			ft_error("Could not get data address from texture img pointer");
		v->textures[i] = tex;
		ft_putstr("Loaded ");
		ft_putstr((v->sprite_num && i == 4) ? "sprite: " : "texture: ");
		ft_putstr(v->tex_files[i]);
		ft_putstr("\n");
		free(v->tex_files[i++]);
	}
	free(v->tex_files);
}
