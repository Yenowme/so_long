/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:13:43 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/12 18:04:50 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (!dst && !src)
		return (NULL);
	while (n-- > 0)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		if (*(unsigned char *)src == (unsigned char)c)
			return ((void *)dst + 1);
		src++;
		dst++;
	}
	return (NULL);
}
