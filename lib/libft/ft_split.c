/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:59:30 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/12 18:08:18 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**x_malloc(char const *s, char c)
{
	char	**rt;
	int		x_size;

	x_size = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		x_size++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (rt = (char **)malloc(sizeof(char *) * (x_size + 1)));
}

static int	final_free(char **rt, int k)
{
	while (--k > 0)
		free(rt[k]);
	free(rt);
	return (0);
}

static int	ft_split_sub(char const *s, char c, char **rt)
{
	int		i;
	int		index;
	int		y_size;
	int		k;

	k = 0;
	i = 0;
	index = 0;
	while (s[i])
	{
		y_size = 0;
		while (s[i] != c && s[i])
		{
			i++;
			y_size++;
		}
		rt[k] = ft_substr(s, index, y_size);
		if (!rt[k++])
			return (final_free(rt, k));
		while (s[i] == c && s[i])
			i++;
		index = i;
	}
	rt[k] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**rt;

	if (!s)
		return (0);
	if (!*s)
		return (ft_calloc(1, sizeof(char **)));
	while (*s == c && *s)
		s++;
	rt = x_malloc(s, c);
	if (!rt)
		return (0);
	if (!(ft_split_sub(s, c, rt)))
		return (0);
	return (rt);
}
