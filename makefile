RCS	= map_handling.c\
	map_handling2.c\
	so_long.c

OBJS	= $(RCS:.c=.o)

NAME	= so_long

CFLAGS	= -Wall -Werror -Wextra

mlx = ./mlx/libmlx.a

$(NAME)	:
		gcc $(CFLAGS) -o so_long $(RCS) $(mlx) -framework OpenGL -framework AppKit

all	: $(NAME)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all