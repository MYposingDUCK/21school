/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:18:48 by rdolf             #+#    #+#             */
/*   Updated: 2020/11/27 01:35:34 by rdolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t bytes)
{
	unsigned char			*new_dest;
	unsigned char			*new_src;
	unsigned char			symbol;
	size_t					counter;

	if (!dest && !src)
		return (dest);
	new_dest = (unsigned char *)dest;
	new_src = (unsigned char *)src;
	symbol = (unsigned char)c;
	counter = 0;
	while (counter < bytes)
	{
		new_dest[counter] = new_src[counter];
		if (new_dest[counter] == symbol)
			return (dest + (counter + 1));
		counter++;
	}
	return (0);
}
