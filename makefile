RCS	= map_handling.c\
	map_handling2.c\
	so_long.c

OBJS	= $(RCS:.c=.o)

NAME	= so_long

CFLAGS	= -Wall -Werror -Wextra -g

mlx = ./mlx/libmlx.a

$(NAME)	:
		make -C ./mlx
		gcc $(CFLAGS) -o so_long $(RCS) $(mlx) -framework OpenGL -framework AppKit

all	: $(NAME)

clean :
		rm -f $(OBJS)
		make clean -C mlx

fclean : clean
		rm -f $(NAME)
		make clean -C mlx

re : fclean all