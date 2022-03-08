#include"so_long.h"

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
		data.xx = x;
		data.yy = y;
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

void	ftft(char *str)
{
	data.str1 = readstr(str);
	data.mlx = mlx_init();
	data.adwall = "./imgs/wall.xpm";
	data.adbg = "./imgs/bg.xpm";
	data.admario = "./imgs/mario.xpm";
	data.adcollect = "./imgs/collect.xpm";
	data.adexit = "./imgs/exit.xpm";
}