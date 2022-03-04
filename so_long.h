#ifndef SO_LONG_H
# define SO_LONG_H

# include<stdio.h>
# include<unistd.h>
# include<string.h>
# include<stdlib.h>
# include<fcntl.h>
# include<sys/stat.h>
# include"./mlx/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

char	*startgame(char *str);

#endif