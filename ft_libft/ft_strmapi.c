/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:28:50 by rdolf             #+#    #+#             */
/*   Updated: 2020/11/29 19:55:17 by rdolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*smap;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(smap = (char*)malloc(sizeof(*smap) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		smap[i] = f(i, s[i]);
		i++;
	}
	smap[i] = '\0';
	return (smap);
}
