NAME		=	MiniLibX.c
HEADER		=	cub3d.h
SRCS		=	main.c							\
				ft_move.c						\
				ft_move_utils.c						\
				ft_raycasting.c						\
				ft_drawfunctions.c					\
				ft_cub3d_vectorinit.c		\
				ft_key_events.c			\
				ft_cub3d.c			\
				ft_textures.c		\
				ft_cub3d_utils.c		\
				./utils/ft_error.c							\
				./utils/ft_putnbr.c							\
				./utils/ft_atoi.c							\
				./utils/ft_putstr.c							\
				./utils/ft_str_utils.c					\
				./utils/ft_get_next_line_utils.c		\
				./utils/ft_get_next_line.c				\
				./cub_file/ft_cub_settings.c				\
				./utils/ft_str_list_functions.c			\
				./cub_file/ft_cub_settings_map_reading.c	\
				./cub_file/ft_cub_settings_read.c	\
				./cub_file/ft_cub_settings_map_check.c		\
				./cub_file/ft_cub_settings_set_settings.c	\
				./cub_file/ft_cub_settings_player_pos.c	\
				./cub_file/ft_cub_settings_map_floodcheck.c\
				./cub_file/ft_cub_settings_map_create.c
CC1			=	@gcc -I /usr/local/include -I .
FL			=	-Wall -Wextra -Werror
CC2			=	-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -g
OBJS		=	$(SRCS:.c=.o)

all     :   $(SRCS) $(HEADER)
				$(CC1) $(SRCS) $(CC2)
test    :
				@gcc -o testMiniLibx -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit *.c
ccleaner:
				@/bin/rm -f *.o
clean   :
				@/bin/rm -f $(OBJS)
fclean  :   clean
				@/bin/rm -f $(NAME)
re      :   fclean all

#-I usr/local/include main.c -L /usr/local/lib/ -lmlx -framenetwork OpenGL AppKit