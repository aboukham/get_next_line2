#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (s + i);
	return (NULL);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*fresh;
	int		i;

	if (!s || !(fresh = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		fresh[i] = s[i];
	fresh[i] = NULL_BYTE;
	return (fresh);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	if (!s1)
		return (ft_strdup(s2));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(new = (char *)malloc(i + j + 1)))
		return (NULL); 
	new[i + j] = NULL_BYTE;
	k = i;
	while (--i >= 0 || --j >= 0)
	{
		i >= 0 ? new[i] = s1[i] : 0;
		j >= 0 ? new[j + k] = s2[j] : 0;
	}
	free(s1);
	return (new);
}
