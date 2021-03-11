/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:20:04 by rdolf             #+#    #+#             */
/*   Updated: 2020/11/22 16:20:06 by rdolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t count)
{
	unsigned char *dest;

	dest = (unsigned char*)s;
	while (count-- > 0)
		*dest++ = (unsigned char)c;
	return (s);
}
