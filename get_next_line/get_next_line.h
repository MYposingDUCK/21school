/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:48:18 by rdolf             #+#    #+#             */
/*   Updated: 2021/02/09 17:48:20 by rdolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
int	get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *str1, const char *str2);
char	*ft_strjoin(char *s1, char *s2);

#endif

