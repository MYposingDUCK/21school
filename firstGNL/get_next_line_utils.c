#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strdup(const char *src)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	if (!(s = malloc(sizeof(*s) * len + 1)))
		return (NULL);
	while (i < len)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ch;

	i = 0;
	ch = (char *)s;
	while (ch[i] != (char)c)
	{
		if (ch[i] == '\0')
			return (0);
		i++;
	}
	return (ch + i);
}

char		*ft_strcpy(char *str1, const char *str2)
{
	int		i;

	i = 0;
	while (str2[i] != '\0')
	{
		str1[i] = str2[i];
		++i;
	}
	str1[i] = '\0';
	return (str1);
}

/*char	*ft_strjoin(char  *s1, char *s2)
{
	size_t	len;
	size_t	i;
	char	*strj;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(strj = (char*)malloc(sizeof(*strj) * len + 1)))
		return (NULL);
	while (*s1 != '\0')
		strj[i++] = *s1++;
	while (*s2 != '\0')
		strj[i++] = *s2++;

	strj[i] = '\0';
	//free(s1);
	return (strj);
}*/
char		*ft_strjoin(char  *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (!s1 | !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}