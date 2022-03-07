#ifndef SO_LONG_H
# define SO_LONG_H

# include<stdio.h>
# include<unistd.h>
# include<string.h>
# include<stdlib.h>
# include<fcntl.h>
# include<sys/stat.h>
# include"./mlx/mlx.h"
# include"./ft_printf/ft_printf.h"

struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	char	*str1;
	char	*adwall;
	char	*adbg;
	char	*admario;
	char	*adcollect;
	char	*adexit;
	int		img_height;
	int		img_width;
	char	*mario;
	char	*backg;
	int		x;
	int		y;
	int		i;
	int		j;
	char	*last;
	char	*wall;
	char	*collect;
	char	*exit;
	int		v;
	int		z;
	int		counter;
	int		cnb;
	int		xx;
	int		yy;
}				data;



int		main(int argc, char **argv);

char	*ft_strnstr(char *str, char *to_find);

int		ft_open(char *str);

char	*ft_strjoin(char *s1, char *s2);

int		ft_read(int fd);

int		ft_strlen(char *str);

char	*ft_strrev(char *str);

int		wordscount(char const *s, char c);

char	**ft_split(char const *s, char c);

char	*ft_strcpy(char *last, char *map, int i, int j);

char	*ft_strchr(char *s, int c);

char	*ft_strdup(char *s1);

#endif
