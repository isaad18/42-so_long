/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 02:16:24 by isaad             #+#    #+#             */
/*   Updated: 2022/11/03 13:11:22 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long.h"

int	wordscount(char const *s, char c)
{
	int	i;
	int	words;
	int	flag;

	i = 0;
	words = 0;
	flag = 1;
	if (s[0] == c)
		return (0);
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] == c) || (s[i] == c && s[i + 1] == '\0'))
			return (0);
		if (s[i] == c && !flag)
			flag = 1;
		else if (s[i] != c && flag)
		{
			words++;
			flag = 0;
		}
		i++;
	}
	return (words);
}

char	*wordscut(char const *s, int len, int start)
{
	int		i;

	i = 0;
	data.c = (char *)malloc(len + 1);
	if (!data.c)
		return (0);
	while (len > 0)
	{
		data.c[i++] = s[start - len];
		len--;
	}
	data.c[i] = '\0';
	return (data.c);
}

void	wordsplit(char **strs, char c, char const *s, int words)
{
	int	i;
	int	strl;
	int	word;

	i = 0;
	word = 0;
	strl = 0;
	while (word < words)
	{
		while (s[i] && s[i] == c)
			++i;
		while (s[i] != c && s[i])
			if (i++ >= 0)
				strl++;
		strs[word++] = wordscut(s, strl, i);
		strl = 0;
	}
	strs[word] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		words;

	if (!s)
		return (0);
	words = wordscount(s, c);
	data.a = (char **)malloc((words + 1) * sizeof(char *));
	if (!data.a)
		return (0);
	wordsplit(data.a, c, s, words);
	return (data.a);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char )c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char )c)
		return ((char *)(s + i));
	return (0);
}
