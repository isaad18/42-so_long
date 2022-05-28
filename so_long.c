/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 02:02:29 by isaad             #+#    #+#             */
/*   Updated: 2022/05/09 17:25:18 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	fire(int keycode)
{
	if (keycode == 49)
	{
		data.str2 = data.str1;
		data.jj = data.j;
		data.ii = data.i;
		data.xf = data.x;
		data.yf = data.y;
		firean();
	}
}

int	moveit(int keycode)
{
	if (keycode == 53)
	{
		freeme();
		exit(0);
	}
	right(keycode);
	left(keycode);
	up(keycode);
	down(keycode);
	fire(keycode);
	ft_printf("%d\n", data.steps);
	if (data.counter == data.cnb && data.str1[data.i] == 'E')
	{
		mlx_destroy_window(data.mlx, data.mlx_win);
		ft_printf("%s", "game over");
		freeme();
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
	mlx_hook(data.mlx_win, 17, 1L<<5, closew, &data);
	makeimgs();
	data.j++;
	mlx_key_hook(data.mlx_win, moveit, &data);
	mlx_loop(data.mlx);
	return (str);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		data.sh = (char *)malloc(i + 1);
		i = 0;
		while (argv[1][i])
		{
			data.sh[i] = argv[1][i];
			i++;
		}
		data.sh[i] = '\0';
		j = ft_open(data.sh);
		print_error(j);
		if (j == 1)
			startgame(data.sh);
	}
	else
		printf("%s", "error, wrong number of arguements");
	return (0);
}
