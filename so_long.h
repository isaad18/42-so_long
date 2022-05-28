/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 02:26:13 by isaad             #+#    #+#             */
/*   Updated: 2022/05/04 14:38:24 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*adfire;
	char	*adbg;
	char	*admario;
	char	*adcollect;
	char	*adexit;
	int		img_height;
	int		img_width;
	char	*mario;
	char	*fire;
	char	*backg;
	int		x;
	int		y;
	int		i;
	int		j;
	char	*str2;
	int		xf;
	int		yf;
	int		ii;
	int		jj;
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
	int		l;
	int		ll;
	int		lll;
	int		steps;
	char	**a;
	char	*c;
	char	*sh;
	char	*ss;
	char	*lastt;
	int		lastkey;
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

int		print_error(int j);

char	*startgame(char *str);

void	ftft(char *str);

int		moveit(int keycode);

int		down(int keycode);

int		up(int keycode);

int		right(int keycode);

int		left(int keycode);

void	ii(void);

void	makeimgs(void);

void	putimage(char c, int x, int y);

char	*readstr(char *str);

int		checkline(int counter, int i, char **s, int j);

int		checktop(char **s, int j);

int		checkbot(char **s, int i, int j);

int		checkmap(char *str);

int		ft_read(int fd);

int		ft_open(char *str);

void	iiii(void);

int		closew(int keycode);

void	freeme(void);

int		firean(void);

#endif
