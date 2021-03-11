/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:35:13 by rdolf             #+#    #+#             */
/*   Updated: 2020/11/27 21:35:27 by rdolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_cpy(char *dest, char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static size_t	ft_count_words(const char *str, char c)
{
	size_t		i;
	size_t		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (!str[i])
			break ;
		words++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (words);
}

static size_t	ft_cut_words(const char *str, size_t words, char **rtrn, char c)
{
	size_t		w;
	size_t		start;
	size_t		end;

	w = 0;
	start = 0;
	while (w < words && str[start])
	{
		while (str[start] == c)
			start++;
		end = start;
		while (str[end] && str[end] != c)
			end++;
		if (!(rtrn[w] = malloc(end - start + 1)))
			return (0);
		ft_cpy(rtrn[w], (char *)str + start, end - start);
		start = end + 1;
		w++;
	}
	return (1);
}

char			**ft_split(char const *s, char c)
{
	size_t	words;
	char	**rtrn;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (words == 0)
	{
		if (!(rtrn = malloc(sizeof(*rtrn))))
			return (NULL);
		rtrn[0] = NULL;
		return (rtrn);
	}
	if (!(rtrn = malloc((words + 1) * sizeof(*rtrn))))
		return (NULL);
	if (!ft_cut_words(s, words, rtrn, c))
		return (NULL);
	rtrn[words] = 0;
	return (rtrn);
}
