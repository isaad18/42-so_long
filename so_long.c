#include"so_long.h"

int	moveit(int keycode)
{
	right(keycode);
	left(keycode);
	up(keycode);
	down(keycode);
	if (keycode == 53)
		exit(0);
	if (data.counter == data.cnb && data.str1[data.i] == 'E')
	{
		mlx_destroy_window(data.mlx, data.mlx_win);
		exit(0);
	}
	return (0);
}

char	*startgame(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	ftft(str);
	ii();
	data.mlx_win = mlx_new_window(data.mlx, i, j, "mario");
	while (data.str1[i])
	{
		if (data.str1[i] == '\n')
			j++;
		if (data.str1[i] == 'C')
			data.cnb++;
		i++;
	}
	i /= j;
	j *= 64;
	i *= 64;
	data.mlx_win = mlx_new_window(data.mlx, i, j, "mario");
	makeimgs();
	data.j++;
	mlx_key_hook(data.mlx_win, moveit, &data);
	mlx_loop(data.mlx);
	return (str);
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
			i++;
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