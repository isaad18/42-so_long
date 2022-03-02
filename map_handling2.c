#include"so_long.h"

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
	char	*c;
	int		i;

	i = 0;
	c = (char *)malloc(len + 1);
	if (!c)
		return (0);
	while (len > 0)
	{
		c[i++] = s[start - len];
		len--;
	}
	c[i] = '\0';
	return (c);
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
	char	**a;
	int		words;

	if (!s)
		return (0);
	words = wordscount(s, c);
	a = (char **)malloc((words + 1) * sizeof(char *));
	if (!a)
		return (0);
	wordsplit(a, c, s, words);
	return (a);
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

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
