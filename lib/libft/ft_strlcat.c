/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeong <yejeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:11:13 by yejeong           #+#    #+#             */
/*   Updated: 2021/05/16 18:35:35 by yejeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_s;
	size_t	src_s;
	size_t	i;
	size_t	j;

	src_s = ft_strlen(src);
	dest_s = ft_strlen(dest);
	i = 0;
	j = dest_s;
	while (j < size - 1 && src[i] && size > dest_s + 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	if (size >= j)
		dest[j] = '\0';
	if (dest_s > size)
		return (src_s + size);
	return (src_s + dest_s);
}
