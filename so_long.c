#include"so_long.h"

char	*startgame(char *str)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, str);
	img.img = mlx_new_image(mlx, 64, 64);
	img.addr = mlx_get_data_addr("mario.png", &img.8, &img.64, &img.endian);
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
		printf("%s", "error, invalid map");
	if (j == 4)
		printf("%s", "error, wrong map input");
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