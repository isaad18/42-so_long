/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 02:05:14 by isaad             #+#    #+#             */
/*   Updated: 2022/11/03 13:11:22 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long.h"

char	*readstr(char *str)
{
	int		fd;
	char	s[2];
	int		i;
	char	*str1;

	s[1] = '\0';
	i = 1;
	fd = open(str, O_RDONLY);
	str1 = ft_strdup("");
	while (i == 1)
	{
		i = read(fd, s, 1);
		str1 = ft_strjoin(str1, s);
	}
	data.lastt = (char *)malloc(ft_strlen(str1));
	i = ft_strlen(str1) - 1;
	data.lastt[i] = 0;
	fd = 0;
	data.lastt = ft_strcpy(data.lastt, str1, i, fd);
	free (str1);
	return (data.lastt);
}

int	left(int keycode)
{
	if (keycode == 0 && data.str1[data.i - 1] != '1')
	{
		data.lastkey = keycode;
		data.steps++;
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.backg, data.x, data.y);
		data.x -= 64;
		data.i--;
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.mario, data.x, data.y);
		if (data.str1[data.i] == 'C')
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win,
				data.backg, data.x, data.y);
			mlx_put_image_to_window(data.mlx, data.mlx_win,
				data.mario, data.x, data.y);
			data.str1[data.i] = '0';
			data.counter++;
		}
		if (data.counter == data.cnb)
			mlx_put_image_to_window(data.mlx, data.mlx_win,
				data.exit, data.xx, data.yy);
	}
	return (0);
}

int	right(int keycode)
{
	if (keycode == 2 && data.str1[data.i + 1] != '1')
	{
		data.lastkey = keycode;
		data.steps++;
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.backg, data.x, data.y);
		data.x += 64;
		data.i++;
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.mario, data.x, data.y);
		if (data.str1[data.i] == 'C')
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win,
				data.backg, data.x, data.y);
			mlx_put_image_to_window(data.mlx, data.mlx_win,
				data.mario, data.x, data.y);
			data.str1[data.i] = '0';
			data.counter++;
		}
		if (data.counter == data.cnb)
			mlx_put_image_to_window(data.mlx, data.mlx_win,
				data.exit, data.xx, data.yy);
	}
	return (0);
}

int	up(int keycode)
{
	if (keycode == 13 && data.str1[data.i - data.j] != '1')
	{
		data.lastkey = keycode;
		data.steps++;
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.backg, data.x, data.y);
		data.y -= 64;
		data.i -= data.j;
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.mario, data.x, data.y);
		if (data.str1[data.i] == 'C')
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win,
				data.backg, data.x, data.y);
			mlx_put_image_to_window(data.mlx, data.mlx_win,
				data.mario, data.x, data.y);
			data.str1[data.i] = '0';
			data.counter++;
		}
		if (data.counter == data.cnb)
			mlx_put_image_to_window(data.mlx, data.mlx_win,
				data.exit, data.xx, data.yy);
	}
	return (0);
}

int	down(int keycode)
{
	if (keycode == 1 && data.str1[data.i + data.j] != '1'
		&& data.str1[data.i + data.j])
	{
		data.lastkey = keycode;
		data.steps++;
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.backg, data.x, data.y);
		data.y += 64;
		data.i += data.j;
		mlx_put_image_to_window(data.mlx, data.mlx_win,
			data.mario, data.x, data.y);
		if (data.str1[data.i] == 'C')
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win,
				data.backg, data.x, data.y);
			mlx_put_image_to_window(data.mlx, data.mlx_win,
				data.mario, data.x, data.y);
			data.str1[data.i] = '0';
			data.counter++;
		}
		if (data.counter == data.cnb)
			mlx_put_image_to_window(data.mlx, data.mlx_win,
				data.exit, data.xx, data.yy);
	}
	return (0);
}
