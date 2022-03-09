/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 02:16:18 by isaad             #+#    #+#             */
/*   Updated: 2022/03/09 02:24:07 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	checktop(char **s, int j)
{
	while (s[0][j])
	{
		if (s[0][j] == '1')
			j++;
		else
			return (0);
	}
	return (1);
}

int	checkbot(char **s, int i, int j)
{
	while (s[i - 1][j])
	{
		if (s[i - 1][j] == '1')
			j++;
		else
			return (0);
	}
	return (1);
}

int	checkmap(char *str)
{
	char	**s;
	int		j;
	int		counter;
	int		l[2];

	iiii();
	j = 0;
	counter = 0;
	l[1] = wordscount(str, '\n');
	l[0] = l[1];
	if (l[0] == 0)
		return (0);
	s = ft_split(str, '\n');
	j = checktop(s, j);
	if (j == 0)
		return (0);
	l[0] = checkline(counter, l[1], s, j);
	if (l[0] == 0)
		return (0);
	j = 0;
	j = checkbot(s, l[0], j);
	if (j == 0)
		return (0);
	return (1);
}

int	ft_read(int fd)
{
	int		i;
	char	str[2];
	char	*map;
	char	*last;
	int		j;

	j = 0;
	map = ft_strdup("");
	i = 1;
	str[1] = '\0';
	while (i == 1)
	{
		i = read(fd, &str[0], 1);
		map = ft_strjoin(map, str);
	}
	last = (char *)malloc(ft_strlen(map));
	last[i] = 0;
	i = ft_strlen(map) - 1;
	last = ft_strcpy(last, map, i, j);
	i = checkmap(last);
	free (map);
	free (last);
	return (i);
}

int	ft_open(char *str)
{
	int	fd;
	int	j;

	str = ft_strrev(str);
	if (ft_strnstr(str, "reb.") == 0)
		return (2);
	str = ft_strrev(str);
	fd = open(str, O_RDONLY);
	j = ft_read(fd);
	if (j == 0)
		return (4);
	return (j);
}
