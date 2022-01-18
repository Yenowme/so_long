/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:51:57 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/12 18:02:38 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rt;

	rt = malloc(sizeof(t_list));
	if (!rt)
		return (0);
	rt->content = content;
	rt->next = 0;
	return (rt);
}
