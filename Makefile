NAME		=	cub3D
HEADER		=	cub3d.h
SRCS		=	main.c									\
				cub/ft_cub_settings.c					\
				cub/ft_cub_settings_cases_ceiling.c		\
				cub/ft_cub_settings_cases_floor.c		\
				cub/ft_cub_settings_cases_res.c			\
				cub/ft_cub_settings_cases_sprite.c		\
				cub/ft_cub_settings_cases_tex.c			\
				cub/ft_cub_settings_map_check.c			\
				cub/ft_cub_settings_map_create.c		\
				cub/ft_cub_settings_map_floodcheck.c	\
				cub/ft_cub_settings_map_reading.c		\
				cub/ft_cub_settings_player_pos.c		\
				cub/ft_cub_settings_read.c				\
				ft_cub3d.c								\
				ft_cub3d_utils.c						\
				ft_cub3d_vectorinit.c					\
				ft_drawfunctions.c						\
				ft_key_events.c							\
				ft_move.c								\
				ft_move_utils.c							\
				ft_raycasting.c							\
				ft_raycasting_sprite.c					\
				ft_screenshot.c							\
				ft_sprite_funcs.c						\
				ft_sprites_sort.c						\
				ft_textures.c							\
				utils/ft_atoi.c							\
				utils/ft_error.c						\
				utils/ft_get_next_line.c				\
				utils/ft_get_next_line_utils.c			\
				utils/ft_print_cond.c					\
				utils/ft_putnbr.c						\
				utils/ft_putstr.c						\
				utils/ft_str_list_functions.c			\
				utils/ft_str_utils.c					
CC			=	@gcc -Wall -Wextra -Werror -g
INCLUDES	= -I. -I/usr/local/include
LINKS			=	-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
OBJS		=	$(SRCS:.c=.o)

all     :   $(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
				$(CC) $(INCLUDES) $(OBJS) $(LINKS) -o $@
%.o		:	%.c
				$(CC) -c $(INCLUDES) -O3 -o $@ $<

clean   :
				@/bin/rm -f $(OBJS)

fclean  :   clean
				@/bin/rm -f $(NAME)

re      :   fclean all

.PHONY	:	all clean fclean re
