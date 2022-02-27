RCS	= map_handling.c	map_handling2.c	so_long.c	\

OBJS	= $(RCS:.c=.o)

NAME	= so_long.a

CFLAGS	= -Wall -Werror -Wextra

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME)	: $(OBJS)
		ar rcs $(NAME) $(OBJS)
		gcc $(CFLAGS) $(NAME) $(OBJS)

all	: $(NAME)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all