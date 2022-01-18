/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:34:56 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/12 18:16:18 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && (*(unsigned char *)s1 == *(unsigned char *)s2) && *s1)
	{
		n--;
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
