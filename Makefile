NAME		=	cub3D
HEADER		=	cub3d.h
SRCS		=	main.c										\
				ft_cub_settings.c							\
				ft_cub_settings_cases_ceiling.c				\
				ft_cub_settings_cases_floor.c				\
				ft_cub_settings_cases_res.c					\
				ft_cub_settings_cases_sprite.c				\
				ft_cub_settings_cases_tex.c					\
				ft_cub_settings_map_check.c					\
				ft_cub_settings_map_create.c				\
				ft_cub_settings_map_floodcheck.c			\
				ft_cub_settings_map_reading.c				\
				ft_cub_settings_player_pos.c				\
				ft_cub_settings_read.c						\
				ft_atoi.c									\
				ft_error.c									\
				ft_get_next_line.c							\
				ft_get_next_line_utils.c					\
				ft_print_cond.c								\
				ft_putnbr.c									\
				ft_putstr.c									\
				ft_str_list_functions.c						\
				ft_str_utils.c								\
				ft_cub3d.c									\
				ft_cub3d_utils.c							\
				ft_cub3d_vectorinit.c						\
				ft_drawfunctions.c							\
				ft_key_events.c								\
				ft_move.c									\
				ft_move_utils.c								\
				ft_raycasting.c								\
				ft_raycasting_sprite.c						\
				ft_screenshot.c								\
				ft_sprite_funcs.c							\
				ft_sprites_sort.c							\
				ft_textures.c
CC			=	@gcc -Wall -Wextra -Werror -g
INCLUDES	= -I /usr/local/include
LINKS			=	-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
OBJS		=	$(SRCS:.c=.o)

all     :   $(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
				$(CC) $(INCLUDES) $(OBJS) $(LINKS) -o $@
clean   :
				@/bin/rm -f $(OBJS)
fclean  :   clean
				@/bin/rm -f $(NAME)
re      :   fclean all
