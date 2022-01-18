/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:12:25 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/12 18:05:52 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)dst;
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		while (len--)
			*temp++ = *(unsigned char *)src++;
	}
	else
	{
		temp += len;
		src += len;
		while (len--)
			*--temp = *(unsigned char *)--src;
	}
	return (dst);
}
