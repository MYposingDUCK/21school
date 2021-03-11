/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 22:21:31 by rdolf             #+#    #+#             */
/*   Updated: 2020/11/26 22:50:57 by rdolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t counter;
	size_t destlen;
	size_t srclen;

	counter = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (dstsize == 0 || (destlen >= dstsize))
		return (srclen + dstsize);
	while ((counter < srclen) && (counter < dstsize - destlen - 1))
	{
		dest[destlen + counter] = src[counter];
		counter++;
	}
	dest[destlen + counter] = '\0';
	return (destlen + srclen);
}
