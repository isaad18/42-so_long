#include"so_long.h"

char	*readstr(char *str)
{
	int		fd;
	char	s[2];
	int		i;
	char	*str1;
	char	*last;

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
	fd = 0;
	last = ft_strcpy(last, str1, i, fd);
	free (str1);
	return (last);
}

void	putimage(char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.wall, x, y);
	if (c == '0')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.backg, x, y);
	if (c == 'C')
	{
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.backg, x, y);
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.collect, x, y);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.backg, x, y);
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.exit, x, y);
	}
	if (c == 'P')
	{
		data.x = x;
		data.y = y;
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.backg, x, y);
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.mario, x, y);
	}
}

void	makeimgs(void)
{
	int		i;

	data.wall = mlx_xpm_file_to_image(data.mlx, data.adwall,
			&data.img_width, &data.img_height);
	data.exit = mlx_xpm_file_to_image(data.mlx, data.adexit,
			&data.img_width, &data.img_height);
	data.collect = mlx_xpm_file_to_image(data.mlx, data.adcollect,
			&data.img_width, &data.img_height);
	data.backg = mlx_xpm_file_to_image(data.mlx, data.adbg,
			&data.img_width, &data.img_height);
	data.mario = mlx_xpm_file_to_image(data.mlx, data.admario,
			&data.img_width, &data.img_height);
	i = 0;
	while (data.str1[i])
	{
		if (data.str1[i] == '\n')
		{
			data.v += 64;
			data.z = 0;
			i++;
		}
		putimage(data.str1[i], data.z, data.v);
		i++;
		data.z += 64;
	}
}

void	ii(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data.z = 0;
	data.v = 0;
	data.img_width = 60;
	data.img_height = 60;
	while (data.str1[i] != 'P')
	{
		i++;
	}
	data.i = i;
	i = 0;
	while (data.str1[i] != '\n')
	{
		j++;
		i++;
	}
	data.j = j;
}

int	moveit(int keycode)
{
	printf("%d\n%d\n%d\n%d\n", data.i, data.j, data.x, data.y);
	if (keycode == 13 && data.str1[data.i - data.j] != '1')
	{
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.backg, data.x, data.y);
		data.y -= 64;
		data.i -= data.j;
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.mario, data.x, data.y);
	}
	if (keycode == 0 && data.str1[data.i - 1] != '1')
	{
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.backg, data.x, data.y);
		data.x -= 64;
		data.i--;
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.mario, data.x, data.y);
	}
	if (keycode == 1 && data.str1[data.i + data.j] != '1'
		&& data.str1[data.i + data.j])
	{
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.backg, data.x, data.y);
		data.y += 64;
		data.i += data.j;
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.mario, data.x, data.y);
	}
	if (keycode == 2 && data.str1[data.i + 1] != '1')
	{
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.backg, data.x, data.y);
		data.x += 64;
		data.i++;
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.mario, data.x, data.y);
	}
	return (0);
}

char	*startgame(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	data.str1 = readstr(str);
	data.mlx = mlx_init();
	data.adwall = "./imgs/wall.xpm";
	data.adbg = "./imgs/bg.xpm";
	data.admario = "./imgs/mario.xpm";
	data.adcollect = "./imgs/collect.xpm";
	data.adexit = "./imgs/exit.xpm";
	ii();
	data.mlx_win = mlx_new_window(data.mlx, i, j, "mario");
	while (data.str1[i])
	{
		if (data.str1[i] == '\n')
			j++;
		i++;
	}
	i /= j;
	j *= 64;
	i *= 64;
	printf ("%s\n", data.str1);
	data.mlx_win = mlx_new_window(data.mlx, i, j, "mario");
	makeimgs();
	data.j++;
	mlx_key_hook(data.mlx_win, moveit, &data);
	mlx_loop(data.mlx);
	return (str);
}

int	print_error(int j)
{
	if (j == 1)
		return (0);
	if (j == 0)
		ft_printf("%s", "error");
	if (j == 2)
		ft_printf("%s", "error, invalid str1");
	if (j == 4)
		ft_printf("%s", "error, wrong map input");
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
