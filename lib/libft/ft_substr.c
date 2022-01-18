/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:04:52 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/13 12:27:27 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rt;
	int		i;
	size_t	size;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) > len)
		size = len;
	else
		size = ft_strlen(s);
	rt = malloc(sizeof(char) * (size + 1));
	if (!rt)
		return (NULL);
	while (len-- && s[start + i])
	{
		rt[i] = s[start + i];
		i++;
	}
	rt[i] = 0;
	return (rt);
}
