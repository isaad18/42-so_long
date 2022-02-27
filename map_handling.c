#include"so_long.h"



int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char    *ft_strrev(char *str)
{
	int i;
	int len;
	char tmp;

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

char    *ft_strnstr(char *str, char *to_find)
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

int checkline(int counter, int i, char **s, int j, int l, int ll, int lll)
{
    while (counter < i - 1)
    {
        j = 0;
        if ((s[counter][0] != '1') || (s[counter][ft_strlen(s[counter]) - 1] != '1'))
            return (0);
        if(ft_strlen(s[counter]) != ft_strlen(s[counter + 1]))
            return (0);
        while (s[counter][j] != '\0')
        {
            if((s[counter][j] != '1') && (s[counter][j] != '0') && (s[counter][j] != 'E') && (s[counter][j] != 'P') && (s[counter][j] != 'C'))
                return (0);
            if (s[counter][j] == 'P')
                l++;
            else if (s[counter][j] == 'E')
                ll++;
            else if (s[counter][j] == 'C')
                lll++;
            j++;
        }
        counter++;
    }
    if (l != 1 || ll != 1 || lll == 0)
        return (0);
    return (1);
}

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

int checkbot(char **s, int i, int j)
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

int checkmap(char *str)
{
    char    **s;
    int     j;
    int     counter;
    int 	l[5];

    l[2] = 0;
    l[0] = 0;
    j = 0;
    l[1] = 0;
    counter = 0;
    l[4] = wordscount(str, '\n');
    l[3] = l[4];
    if (l[3] == 0)
        return (0);
    s = ft_split(str, '\n');
	j = checktop(s, j);
	if (j == 0)
		return (0);
	l[0] = checkline(counter, l[3], s, j, l[0], l[1], l[2]);
	if (l[0] == 0)
		return (0);
    j = 0;
	j = checkbot(s, l[3], j);
	if (j == 0)
		return (0);
    return (1);
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

int ft_read(int fd)
{
    int i;
    char    str[2];
    char    *map;
    char    *last;
    int     j;

    j = 0;
    map = ft_strdup("");
    i = 1;
    str[1] = '\0';
    while (i == 1)
    {
        i = read(fd, &str[0], 1);
        map = ft_strjoin(map, str);
    }
    if (map[0] == '\0')
	{
        free(map);
		return (0);
	}
    last = (char *)malloc(ft_strlen(map));
	last[i] = 0;
    i = ft_strlen(map) - 1;
	last = ft_strcpy(last, map, i, j);
    i = checkmap(last);
    return (i);
}

int ft_open(char *str)
{
    int fd;
    int j;

    str = ft_strrev(str);
  	if(ft_strnstr(str, "reb.") == 0)
		return (2);
    str = ft_strrev(str);
    fd = open(str, O_RDONLY);
    j = ft_read(fd);
    if (j == 0)
        return (4);
    return (j);
}