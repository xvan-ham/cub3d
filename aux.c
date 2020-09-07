/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:12:28 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/03 18:38:51 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_vectors_initialise(t_vectors *v)
{
	printf("ft_vectors_initialise_s\n");
	v->debug_frame = 1;
	v->win = 0;
	v->img = 0;
	v->img_ptr = 0;
	//v->mlx = 0;
	v->img_bpp = 0;
	v->img_line_size = 0;
	v->img_endian = 0;
	v->textures = 0;
	v->tex_files = 0;
	v->n_textures = 0;
	v->screen_h = 0;//specify defaults here?
	v->screen_w = 0;
	v->flag_key_w_down = 0;
	v->flag_key_a_down = 0;
	v->flag_key_s_down = 0;
	v->flag_key_d_down = 0;
	v->flag_key_left_down = 0;
	v->flag_key_right_down = 0;
	v->flag_stuck = 0;
	v->orientation = W;
	v->fov = 0.66;//0.66
	v->map_height = 0;
	v->map_width = 0;
	v->map_y = 0;
	v->map_x = 0;
	v->pos_y = 0;	
	v->pos_x = 0;	
	v->dir_y = 0;	
	v->dir_x = 0;	
	v->plane_y = 0;	
	v->plane_x = 0;	
	v->camera_y = 0;	
	v->raydir_y = 0;	
	v->raydir_x = 0;
	v->step = 0;	
	v->step_y = 0;	
	v->step_x = 0;		
	v->side_dist_y = 0;
	v->side_dist_x = 0;
	v->delta_dist_y = 0;
	v->delta_dist_x = 0;
 	v->perp_wall_dist = 0;
	v->hit = 0;
	v->side = 0;
	v->move_speed = 0;	
	v->rot_speed = 0;
	v->tex_pos = 0;
	v->tex_y = 0;
	v->tex_x = 0;
	v->wall_y = 0;
	v->wall_x = 0;//used?
	v->n_textures = N_TEXTURES;
	v->flag_sprites = 0;//used?
	if (!(v->textures = (t_texture **)malloc(sizeof(t_texture *))))
		ft_error("Not enough memory for texture array (malloc)");
	if (!(v->tex_files = (char **)malloc(sizeof(char *) * 4)))
		ft_error("Not enough memory for tex_files (strings) array (malloc)");
	printf("ft_vectors_initialise_e\n");
}

int		ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putnbr(double n, const char *base)
{
	int baselen;

	baselen = ft_strlen(base);
	if (n >= baselen)
	{
		ft_putnbr(n / baselen, base);
		ft_putnbr((int)n % baselen, base);
	}
	else
		write(1, &base[(int)n], 1);
}

int		digits(int n)
{
	int digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (0);
}	

void	ft_error(char *s)
{
	ft_putstr("\nFatal Error: ");
	ft_putstr(s);
	ft_putstr("\n");
	exit(1);
}

/*
** Function: char	*ft_strndup(const char *src, size_t chars)
** Allocates sufficient memory for a freeable copy of the string
** 'src', does the copy, and returns a pointer to it.
** Copies at most 'chars' characters from the string
** 'src' always NUL terminating the copied string.
*/

char	*ft_strndup(const char *src, size_t chars)
{
	char	*str;
	char	*strptr;

	if (!src)
		return (0);
	if (!(str = malloc((chars + 1) * sizeof(char))))
		return (0);
	strptr = str;
	while (*src && chars--)
		*(strptr++) = *(src++);
	*strptr = 0;
	return (str);
}

int		ft_atoi(const char *string)
{
	int	sign;
	int	total;

	sign = 1;
	total = 0;
	while (*string == 32 || (*string > 8 && *string < 14))
		string++;
	if (*string == '-')
		sign *= -1;
	if (*string == '-' || *string == '+')
		string++;
	while (*string && *string >= 48 && *string <= 57)
		total = total * 10 + (*(string++) - '0');
	return (total * sign);
}