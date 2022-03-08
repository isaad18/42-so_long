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

int checkline(int counter, int i, char **s, int j)
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
            if((s[counter][j] != '1') && (s[counter][j] != '0') && 
				(s[counter][j] != 'E') && (s[counter][j] != 'P') && (s[counter][j] != 'C'))
                return (0);
            if (s[counter][j] == 'P')
                data.l++;
            else if (s[counter][j] == 'E')
                data.ll++;
            else if (s[counter][j] == 'C')
                data.lll++;
            j++;
        }
        counter++;
    }
    if ((data.l != 1 || data.ll != 1 || data.lll == 0))
        return (0);
    return (1);
}