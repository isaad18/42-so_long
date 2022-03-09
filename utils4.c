/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameeee.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 02:07:26 by isaad             #+#    #+#             */
/*   Updated: 2022/03/09 02:20:42 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		x;
	int		xx;

	x = 0;
	xx = 0;
	if (!s1 || !s2)
		return (0);
	new = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (0);
	while (s1[x] != '\0')
	{
		new[x] = s1[x];
		x++;
	}
	while (s2[xx] != '\0')
	{
		new[x] = s2[xx];
		xx++;
		x++;
	}
	new[x] = '\0';
	free(s1);
	return (new);
}

int	checkline(int co, int i, char **s, int j)
{
	while (co < i - 1)
	{
		j = 0;
		if ((s[co][0] != '1') || (s[co][ft_strlen(s[co]) - 1] != '1'))
			return (0);
		if (ft_strlen(s[co]) != ft_strlen(s[co + 1]))
			return (0);
		while (s[co][j] != '\0')
		{
			if ((s[co][j] != '1') && (s[co][j] != '0') && (s
				[co][j] != 'E') && (s[co][j] != 'P') && (s[co][j] != 'C'))
				return (0);
			if (s[co][j] == 'P')
				data.l++;
			else if (s[co][j] == 'E')
				data.ll++;
			else if (s[co][j] == 'C')
				data.lll++;
			j++;
		}
		co++;
	}
	if ((data.l != 1 || data.ll != 1 || data.lll == 0))
		return (0);
	return (1);
}

void	iiii(void)
{
	data.l = 0;
	data.ll = 0;
	data.lll = 0;
}

int	closew(int keycode)
{
	mlx_destroy_window(data.mlx, data.mlx_win);
	freeme();
	exit(0);
	return (keycode);
}

void	freeme(void)
{
	free(data.a);
	free(data.c);
	free(data.ss);
	free(data.lastt);
	free(data.sh);
}