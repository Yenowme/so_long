/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:11:22 by yejeong           #+#    #+#             */
/*   Updated: 2022/01/18 16:58:09 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rt;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	rt = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!rt)
		return (0);
	while (s1[i])
	{
		rt[i] = s1[i];
		i++;
	}
	while (s2[j])
		rt[i++] = s2[j++];
	rt[i] = 0;
	s1 = 0;
	return (rt);
}

char	*ft_strdup(const char *src)
{
	char	*rt;
	int		i;

	i = 0;
	while (src[i])
		i++;
	rt = malloc(sizeof(char) * i + 1);
	if (!(rt))
		return (0);
	i = 0;
	while (src[i])
	{
		rt[i] = src[i];
		i++;
	}
	rt[i] = 0;
	return (rt);
}
