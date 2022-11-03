RCS	= ./src/map_handling.c\
	./src/map_handling2.c\
	./src/so_long.c\
	./src/utils1.c\
	./src/utils2.c\
	./src/utils3.c\
	./src/utils4.c\
	./src/firing.c\

OBJS	= $(RCS:.c=.o)

NAME	= so_long

CFLAGS	= -Wall -Werror -Wextra -g

mlx = ./mlx/libmlx.a

ft_printf = ./ft_printf/libftprintf.a

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