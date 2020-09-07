/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:13:02 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/07 18:15:07 by xvan-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>

# define MAPHEIGHT 7//40
# define MAPWIDTH 7//24
# define BUFFER_SIZE 5
# define N 0
# define E 1
# define W 2
# define S 3
# define SW 1500//640 //remove when argv is implemented
# define SH 1000//480 //remove when argv is implemented
# define N_TEXTURES 2 //remove when argv is implemented
# define WIN_NAME "Cub3D"
# define PARAM_MOV_SPEED 0.03
# define PARAM_ROT_SPEED 0.04
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

typedef struct			s_str_list
{
	char				*str;
	struct s_str_list	*next;
}						t_str_list;

typedef	struct	s_texture
{
	char		*file_name;
	int			tex_w;
	int			tex_h;
	void		*img;
	char		*img_ptr;
	int			img_bpp;
	int			img_line_size;
	int			img_endian;
}				t_texture;

typedef struct	s_vectors
{
	unsigned int			debug_frame;
	void		*win;//window indentifier
	void		*img;
	char		*img_ptr;
	void		*mlx;//connection identifier
	t_texture	**textures;
	char		**tex_files;
	char		**map;
	int			img_bpp;
	int			img_line_size;
	int			img_endian;
	int			color_floor;
	int			color_sky;
	int			n_textures;
	int			flag_key_w_down;
	int			flag_key_a_down;
	int			flag_key_s_down;
	int			flag_key_d_down;
	int			flag_key_right_down;
	int			flag_key_left_down;
	int			flag_stuck;
	int			map_width;
	int			map_height;
	int			map_y;
	int			map_x;
	double		fov;
	int			orientation;
	double		screen_w;
	double		screen_h;
	double		pos_y;
	double		pos_x;
	double		dir_y;
	double		dir_x;
	double		plane_y;
	double		plane_x;
	double		camera_y;
	double		raydir_y;
	double		raydir_x;
	int			step_y;
	int			step_x;
	double		side_dist_y;
	double		side_dist_x;
	double		delta_dist_y;
	double		delta_dist_x;
	double		perp_wall_dist;
	int			hit;
	int			side;
	double		tex_pos;
	int			tex_y;
	int			tex_x;
	double		wall_y;
	double		wall_x;//used?
	double		step;
	double		move_speed;
	double		rot_speed;
	int			flag_sprites;
}				t_vectors;

void			ft_vectors_initialise(t_vectors *v);
int				ft_strlen(const char *s);
void			ft_putstr(const char *s);
int				digits(int n);
void			ft_error(char *s);
char			*ft_strdup(const char *s);
int				ft_get_next_line(int fd, char **line);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *src, size_t chars);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_process_cub_file(t_vectors *v);
char			*ft_strchr(const char *s, int c);
t_str_list		*ft_str_list_new_element(const char *s);
void			ft_str_list_delete(t_str_list *element);
void			ft_parse_line(t_vectors *v, const char *c, t_str_list **tmp_map, int *flag_map);
void			ft_print_tmp_map(t_str_list *tmp_map);

#endif