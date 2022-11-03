#include"../includes/so_long.h"

int	rightf()
{
	if (data.str2[data.ii] == '0')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.backg, data.xf, data.yf);
	sleep(2);
	data.xf += 64;
	data.ii++;
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.fire, data.x, data.y);
	if (data.str2[data.ii + 1] == '1' || data.str2[data.ii + 1] == 'C')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.backg, data.xf, data.yf);
	return (0);
}

int	leftf()
{
	if (data.str2[data.ii] == '0')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.backg, data.xf, data.yf);
	sleep(2);
	data.xf -= 64;
	data.ii--;
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.fire, data.x, data.y);
	if (data.str2[data.ii - 1] == '1' || data.str2[data.ii - 1] == 'C')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.backg, data.xf, data.yf);
	return (0);
}

int	upf()
{
	if (data.str2[data.ii] == '0')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.backg, data.xf, data.yf);
	sleep(2);
	data.yf -= 64;
	data.ii -= data.jj;
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.fire, data.x, data.y);
	if (data.str2[data.ii - data.jj] == '1' || data.str2[data.ii - data.jj] == 'C')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.backg, data.xf, data.yf);
	return (0);
}

int	downf()
{
	if (data.str2[data.ii] == '0')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.backg, data.xf, data.yf);
	sleep(2);
	data.yf += 64;
	data.ii += data.jj;
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.fire, data.x, data.y);
	if (data.str2[data.ii + data.jj] == '1' || data.str2[data.ii + data.jj] == 'C')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.backg, data.xf, data.yf);
	return (0);
}

int	firean(void)
{
	if (data.lastkey == 2)
		mlx_loop_hook(data.mlx, rightf, &data);
	if (data.lastkey == 0)
		mlx_loop_hook(data.mlx, leftf, &data);
	if (data.lastkey == 13)
		mlx_loop_hook(data.mlx, upf, &data);
	if (data.lastkey == 1)
		mlx_loop_hook(data.mlx, downf, &data);
	return (0);
}