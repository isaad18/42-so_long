#include"so_long.h"

char	*readstr(char *str)
{
	int		fd;
	char	s[2];
	int		i;
	char	*str1;
	char	*last;
	int		j;

	j = 0;
	s[1] = '\0';
	i = 1;
	fd = open(str, O_RDONLY);
	str1 = ft_strdup("");
	while (i == 1)
	{
		i = read(fd, s, 1);
		str1 = ft_strjoin(str1, s);
	}
	last = (char *)malloc(ft_strlen(str1));
    i = ft_strlen(str1) - 1;
	last[i] = 0;
	last = ft_strcpy(last, str1, i, j);
	free (str1);
	return (last);
}

void	putimage(char c, char *wall, char *bg, char *mario, char *collect, int x, int y, void *mlx, void *mlx_win)
{
	if (c == '1')
		mlx_put_image_to_window(mlx, mlx_win, wall, x, y);
	if (c == '0')
		mlx_put_image_to_window(mlx, mlx_win, bg, x, y);
	if (c == 'C')
		mlx_put_image_to_window(mlx, mlx_win, collect, x, y);
	if (c == 'P')
	{
		mlx_put_image_to_window(mlx, mlx_win, bg, x, y);
		mlx_put_image_to_window(mlx, mlx_win, mario, x, y);
	}
}

void	makeimgs(void *mlx, void *mlx_win, char *str1, char *adwall, char *adbg, char *admario, char *adcollect)
{
	int		img_width;
	int		img_height;
	int		x = 0;
	int		y = 0;
	char	*wall;
	char	*bg;
	char	*mario;
	char	*collect;
	int		i;

	i = 0;
	img_width = 60;
	img_height = 60;
	wall = mlx_xpm_file_to_image(mlx, adwall, &img_width, &img_height);
	bg = mlx_xpm_file_to_image(mlx, adbg, &img_width, &img_height);
	mario = mlx_xpm_file_to_image(mlx, admario, &img_width, &img_height);
	collect = mlx_xpm_file_to_image(mlx, adcollect, &img_width, &img_height);
	while (str1[i])
	{
		if (str1[i] == '\n')
		{
			y += 65;
			x = 0;
			i++;
		}
		putimage(str1[i], wall, bg, mario, collect, x, y, mlx, mlx_win);
		i++;
		x += 65;
	}
}

char	*startgame(char *str)
{
	char	*str1;
	void	*mlx;
	char	*adwall = "./imgs/wall.xpm";
	char	*adbg = "./imgs/bg.xpm";
	char	*admario = "./imgs/mario.xpm";
	char	*adcollect = "./imgs/collect.xpm";
	void	*mlx_win;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx = mlx_init();
	str1 = readstr(str);
	while(str1[i])
	{
		if (str1[i] == '\n')
			j++;
		i++;
	}
	j += 1;
	i /= j;
	j *= 64;
	i *= 64;
	mlx_win = mlx_new_window(mlx, i, j, str);
	makeimgs(mlx, mlx_win, str1, adwall, adbg, admario, adcollect);
	mlx_loop(mlx);
	return (str);
}

int	print_error(int	j)
{
	if (j == 1)
		return (0);
	if (j == 0)
		printf("%s", "error");
	if (j == 2)
		printf("%s", "error, invalid str1");
	if (j == 4)
		printf("%s", "error, wrong str1 input");
	return (0);
}

int	main(int argc, char **argv)
{
   	char	*str;
	int		i;
	int		j;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			i++;
		}
		str = (char *)malloc(i + 1);
		i = 0;
		while (argv[1][i])
		{
			str[i] = argv[1][i];
			i++;
		}
		str[i] = '\0';
		j = ft_open(str);
		print_error(j);
		if (j == 1)
			startgame(str);
	}
	else
		printf("%s", "error, wrong number of arguements");
	return (0);
}