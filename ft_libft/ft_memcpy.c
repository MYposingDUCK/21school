/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:47:35 by rdolf             #+#    #+#             */
/*   Updated: 2020/11/27 00:38:47 by rdolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t bytes)
{
	unsigned char *cdest;
	unsigned char *csrc;

	if (!dest && !src)
		return (dest);
	cdest = (unsigned char*)dest;
	csrc = (unsigned char*)src;
	while (bytes--)
		*cdest++ = *csrc++;
	return (dest);
}
