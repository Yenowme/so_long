/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:59:37 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/12 18:16:23 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		i = 0;
		while (haystack[i] == needle[i] && i < len)
		{
			i++;
			if (!needle[i])
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
