/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:31:41 by rdolf             #+#    #+#             */
/*   Updated: 2020/11/29 19:52:30 by rdolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && i < j)
		i++;
	if (i == j)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[j - 1]) && i < j)
		j--;
	str = ft_substr(s1, (unsigned int)i, j - i);
	if (str == NULL)
		return (NULL);
	return (str);
}
