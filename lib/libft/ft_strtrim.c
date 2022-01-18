/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:42:45 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/12 18:17:26 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*rt;
	int		i;

	i = 0;
	if (!s1 || !set)
		return (0);
	while ((ft_strchr(set, *s1)) && *s1)
		s1++;
	start = (char *)s1;
	if (!*start)
		return (ft_strdup(""));
	while (*s1)
		s1++;
	while (ft_strchr(set, *s1) && s1 > start)
		s1--;
	end = (char *)s1;
	rt = malloc(end - start + 2);
	if (!rt)
		return (0);
	while (start <= end)
		rt[i++] = *start++;
	rt[i] = 0;
	return (rt);
}
