/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:17:34 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/12 18:15:23 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		return (NULL);
	while (s1[i])
	{
		rt[i] = s1[i];
		i++;
	}
	while (s2[j])
		rt[i++] = s2[j++];
	rt[i] = 0;
	return (rt);
}
