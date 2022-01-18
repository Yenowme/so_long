/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:52:46 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/12 18:01:29 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	malloc_size(int n, int *size)
{
	if (n != 0)
	{
		malloc_size(n / 10, size);
		*size += 1;
	}
}

static int	set_itoa(char *rt, long long n, int size)
{
	if (n < 10)
	{
		rt[size] = '0' + n;
		return (0);
	}
	else
	{
		set_itoa(rt, n / 10, size - 1);
		rt[size] = '0' + n % 10;
		return (1);
	}
}

char	*ft_itoa(int n)
{
	char		*rt;
	int			size;
	long long	num;
	int			flag;

	flag = 0;
	num = n;
	size = 0;
	malloc_size(n, &size);
	if (n <= 0)
		size++;
	rt = malloc(sizeof(char) * (size + 1));
	if (!rt)
		return (0);
	if (n < 0)
	{
		rt[0] = '-';
		num *= -1;
		flag = 1;
	}
	set_itoa(rt, num, size - 1);
	rt[size] = 0;
	return (rt);
}
