/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:55:46 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/12 17:58:01 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (len--)
	{
		*temp = 0;
		temp++;
	}
}
