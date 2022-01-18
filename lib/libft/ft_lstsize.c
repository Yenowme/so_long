/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeong <yejeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:59:55 by yejeong           #+#    #+#             */
/*   Updated: 2021/05/13 19:03:21 by yejeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	rt;

	if (!lst)
		return (0);
	rt = 1;
	while (lst->next)
	{
		rt++;
		lst = lst->next;
	}
	return (rt);
}
