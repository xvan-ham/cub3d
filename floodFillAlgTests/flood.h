#ifndef FLOOD_H
#define FLOOD_H

# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 5
# define MAPHEIGHT_LIM 200
# define MAPWIDTH_LIM 200
# define N 0
# define E 1
# define W 2
# define S 3

typedef struct			s_str_list
{
	char				*str;
	struct s_str_list	*next;
}						t_str_list;

typedef struct	s_vectors
{
	char		**map;
	int			map_width;
	int			map_height;
	int			map_y;
	int			map_x;
	double		pos_y;
	double		pos_x;
}				t_vectors;

void			ft_parse_line(t_vectors *v, const char *c, t_str_list **tmp_map, int *flag_map);
void	ft_print_map(t_vectors *v, char **map);
void			ft_print_tmp_map(t_str_list *tmp_map);
t_str_list		*ft_str_list_new_element(const char *s);
void			ft_str_list_delete(t_str_list *element);
t_str_list		*ft_str_list_get_element(t_str_list *element, int i);
void			ft_check_map(t_vectors *v, t_str_list *tmp_map);
void			ft_create_map(t_vectors *v, t_str_list *tmp_map);
void			ft_error(const char *str);
int				ft_get_next_line(int fd, char **line);
char			*ft_chars_in_str(const char *chars, const char *str);
char			*ft_strstr(const char *s1, const char *s2);
int				ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
char			*ft_strndup(const char *src, size_t chars);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_process_cub_file(t_vectors *v);

#endif