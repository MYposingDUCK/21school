/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:48:05 by rdolf             #+#    #+#             */
/*   Updated: 2021/02/09 17:48:08 by rdolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_strclear(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

static char		*ft_strnew(int i)
{
	char		*str;

	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

static char		*check_remainder_line(char **remainder_line, char **line)
{
	char		*p;

	p = NULL;
	*line = NULL;
	if (*remainder_line != NULL)
	{
		if ((p = ft_strchr(*remainder_line, '\n')))
		{
			*p = '\0';
			p++;
			*line = ft_strdup(*remainder_line);
			if (*p)
				ft_strcpy(*remainder_line, p);
			else
				ft_strclear(&*remainder_line);
		}
		else
		{
			*line = ft_strdup(*remainder_line);
			ft_strclear(&*remainder_line);
		}
	}
	else
		*line = ft_strnew(0);
	return (p);
}

	int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	char		*p;
	int		byte_was_read;
	static char	*remainder_line[10000];
	char		*tmp;

	if ((!line || fd < 0 || BUFFER_SIZE < 1 || (read(fd, buff, 0)) < 0))
		return (-1);
	p = check_remainder_line(&remainder_line[fd], line);
	while ((!p) && (byte_was_read = read(fd, buff, BUFFER_SIZE)))
	{
		buff[byte_was_read] = '\0';
		if ((p = ft_strchr(buff, '\n')))
		{
			*p = '\0';
			p++;
			if ((*p) && !(remainder_line[fd] = ft_strdup(p)))
				return (-1);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buff)))
			return (-1);
		
		free(tmp);
	}
	return (p ? 1 : 0);
}
