/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:27:40 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/12 18:14:59 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*rt;
	int		i;

	i = 0;
	while (src[i])
		i++;
	rt = malloc(sizeof(char) * i + 1);
	if (!rt)
		return (0);
	i = 0;
	while (src[i])
	{
		rt[i] = src[i];
		i++;
	}
	rt[i] = '\0';
	return (rt);
}
