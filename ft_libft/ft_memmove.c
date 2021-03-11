/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:06:18 by rdolf             #+#    #+#             */
/*   Updated: 2020/11/25 15:41:55 by rdolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*new_dest;
	char		*new_src;
	size_t		counter;

	if (!dest && !src)
		return (dest);
	new_dest = (char *)dest;
	new_src = (char *)src;
	if (src < dest)
	{
		counter = len;
		while (counter--)
			new_dest[counter] = new_src[counter];
	}
	else
	{
		counter = 0;
		while (counter < len)
		{
			new_dest[counter] = new_src[counter];
			counter++;
		}
	}
	return (dest);
}
