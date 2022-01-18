/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:36:17 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/12 18:16:02 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rt;
	int		i;

	i = 0;
	if (!s)
		return (0);
	rt = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!rt)
		return (0);
	while (s[i])
	{
		rt[i] = f(i, s[i]);
		i++;
	}
	rt[i] = 0;
	return (rt);
}
