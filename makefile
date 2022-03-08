RCS	= map_handling.c\
	map_handling2.c\
	so_long.c\
	gameeee.c\
	gameee.c\
	gamee.c\
	game.c

OBJS	= $(RCS:.c=.o)

NAME	= so_long

CFLAGS	= -Wall -Werror -Wextra -g

mlx = ./mlx/libmlx.a

ft_printf = ./ft_printf/libftprintf.a

$(NAME)	:
		make -C ./mlx
		make -C ./ft_printf
		gcc $(CFLAGS) -o so_long $(RCS) $(mlx) $(ft_printf) -framework OpenGL -framework AppKit

all	: $(NAME)

clean :
		rm -f $(OBJS)
		make clean -C mlx

fclean : clean
		rm -f $(NAME)
		make clean -C mlx

re : fclean all