/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvan-ham <xvan-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:13:02 by xvan-ham          #+#    #+#             */
/*   Updated: 2020/09/16 19:49:59 by xvan-ham         ###   ########.fr       */
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

# define BUFFER_SIZE 5
# define N 0
# define E 1
# define W 2
# define S 3
# define SW 1500
# define SH 1000
# define SCREEN_WIDTH_LL 100
# define SCREEN_WIDTH_UL 3072
# define SCREEN_HEIGHT_LL 100
# define SCREEN_HEIGHT_UL 1920
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

typedef	struct			s_texture
{
	char				*file_name;
	char				*img_ptr;
	int					img_bpp;
	int					img_endian;
	int					img_line_size;
	int					tex_h;
	int					tex_w;
	void				*img;
}						t_texture;

typedef struct			s_color
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;

typedef struct			s_vectors
{
	char				**map;
	char				**tex_files;
	char				*img_ptr;
	double				camera_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				dir_x;
	double				dir_y;
	double				fov;
	double				move_speed;
	double				perp_wall_dist;
	double				plane_x;
	double				plane_y;
	double				pos_x;
	double				pos_y;
	double				raydir_x;
	double				raydir_y;
	double				rot_speed;
	double				screen_h;
	double				screen_w;
	double				side_dist_x;
	double				side_dist_y;
	double				step;
	double				tex_pos;
	double				wall_x;
	double				wall_y;
	int					flag_key_a_down;
	int					flag_key_d_down;
	int					flag_key_left_down;
	int					flag_key_right_down;
	int					flag_key_s_down;
	int					flag_key_w_down;
	int					flag_sprite;
	int					hit;
	int					img_bpp;
	int					img_endian;
	int					img_line_size;
	int					map_height;
	int					map_width;
	int					map_x;
	int					map_y;
	int					orientation;
	int					side;
	int					step_x;
	int					step_y;
	int					tex_x;
	int					tex_y;
	int					x;
	t_color				*floor;
	t_color				*sky;
	t_texture			**textures;
	void				*img;
	void				*mlx;
	void				*win;
}						t_vectors;

char					*ft_chars_in_str(const char *chars, const char *str);
char					*ft_strchr(const char *s, int c);
char					*ft_strdup(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strndup(const char *src, size_t chars);
char					*ft_strstr(const char *s1, const char *s2);
int						digits(int n);
int						ft_atoi(const char *string);
int						ft_choose_wall_texture(t_vectors *v);
int						ft_exit(int key);
int						ft_get_next_line(int fd, char **line);
int						ft_move(t_vectors *v);
int						ft_press_key(int key, void *param);
int						ft_release_key(int key, void *param);
int						ft_strlen(const char *s);
t_str_list				*ft_str_list_get_element(t_str_list *element, int i);
t_str_list				*ft_str_list_new_element(const char *s);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					flag_left(t_vectors *v, int flag);
void					flag_right(t_vectors *v, int flag);
void					ft_add_to_tmp_map(t_vectors *v, const char *c,
					t_str_list **tmp_map);
void					ft_cases_ceiling(t_vectors *v, const char *str);
void					ft_cases_floor(t_vectors *v, const char *str);
void					ft_cases_floor(t_vectors *v, const char *str);
void					ft_cases_res(t_vectors *v, const char *str);
void					ft_cases_sprite(t_vectors *v, const char *str);
void					ft_cases_tex(t_vectors *v, const char *str);
void					ft_check_config(t_vectors *v, const char *c);
void					ft_check_map(t_vectors *v, t_str_list *tmp_map);
void					ft_color_pixel(char *s, char *s_tex);
void					ft_create_map(t_vectors *v, t_str_list *tmp_map);
void					ft_cub3d(void);
void					ft_draw_floor(t_vectors *v, int x, int draw_end);
void					ft_draw_sky(t_vectors *v, int x, int draw_start);
void					ft_draw_vert(t_vectors *v, int draw_start, int draw_end,
					int tex_n);
void					ft_error(char *s);
void					ft_floodcheck(t_vectors *v, int pos_x, int pos_y);
void					ft_load_player_position(t_vectors *v);
void					ft_load_tex_files(t_vectors *v);
void					ft_load_textures(t_vectors *v);
void					ft_mlx_start(t_vectors *v);
void					ft_parse_line(t_vectors *v, const char *c,
					t_str_list **tmp_map, int *flag_map);
void					ft_print_map(t_vectors *v, char **map);
void					ft_print_tmp_map(t_str_list *tmp_map);
void					ft_process_cub_file(t_vectors *v);
void					ft_putstr(const char *s);
void					ft_raycaster_defaults(t_vectors *v);
void					ft_raycasting(t_vectors *v);
void					ft_set_orientation_params(t_vectors *v);
void					ft_str_list_delete(t_str_list *element);
void					ft_vectors_initialise(t_vectors *v);

#endif
