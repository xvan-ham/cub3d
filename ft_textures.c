/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:10:34 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/15 19:20:44 by xvan-ham         ###   ########.fr       */
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
	v->tex_files[0] = ft_strdup("./Textures/brick_4.xpm");
	v->tex_files[1] = ft_strdup("./Textures/brick_1.xpm");
	v->tex_files[2] = ft_strdup("./Textures/brick_2.xpm");
	v->tex_files[3] = ft_strdup("./Textures/brick_3.xpm");
}

void	ft_load_textures(t_vectors *v)
{
	t_texture	*tex;
	int			i;

	i = 0;
	if (!v)
		ft_error("received null pointer: ft_load_textures");
	ft_load_tex_files(v);
	while (i < 4)
	{
		if (!(tex = malloc(sizeof(t_texture))))
			ft_error("Not enough memory for texture (malloc)");
		if (!(tex->img = mlx_xpm_file_to_image(v->mlx, v->tex_files[i],
			&(tex->tex_w), &(tex->tex_h))))
			ft_error("Could not read texture");
		tex->file_name = v->tex_files[i];
		if (!(tex->img_ptr = mlx_get_data_addr(tex->img,
		&(tex->img_bpp), &(tex->img_line_size),
			&(tex->img_endian))))
			ft_error("Could not get data address from texture img pointer");
		v->textures[i] = tex;
		printf("Loaded texture: %s\n", v->tex_files[i]);
		i++;
	}
	printf("ft_load_textures_e\n");
}
