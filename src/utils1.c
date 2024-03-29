/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 02:04:00 by isaad             #+#    #+#             */
/*   Updated: 2022/11/03 13:11:22 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long.h"

char	*ft_strdup(char *s1)
{
	size_t	i;

	data.ss = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!data.ss)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		data.ss[i] = s1[i];
		i++;
	}
	data.ss[i] = 0;
	return (data.ss);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (len > i)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

char	*ft_strcpy(char *last, char *map, int i, int j)
{
	while (j < i)
	{
		last[j] = map[j];
		j++;
	}
	return (last);
}

char	*ft_strnstr(char *str, char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	if (!str && !to_find)
		return (NULL);
	j = 0;
	while (str[i] && i < 1)
	{
		while (str[i + j] && to_find[j] && str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
