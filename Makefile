NAME		=	MiniLibX.c
HEADER		=	cub3d.h
SRCS		=	main.c						\
				aux.c						\
				ft_get_next_line_utils.c	\
				ft_get_next_line.c			\
				ft_cub_settings.c
CC1			=	@gcc -I /usr/local/include
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