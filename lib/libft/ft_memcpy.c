/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeong <yejeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:47:22 by yejeong           #+#    #+#             */
/*   Updated: 2021/05/17 16:48:10 by yejeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)dst;
	if (dst == src)
		return (dst);
	while (n--)
	{
		*temp = *(unsigned char *)src;
		temp++;
		src++;
	}
	return (dst);
}
