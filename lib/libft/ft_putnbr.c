/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:48:50 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/17 17:22:12 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, int *rt)
{
	char	a;

	if (n == -2147483648)
	{
		*rt = write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		*rt += write(1, "-", 1);
		n *= -1;
		ft_putnbr(n, rt);
	}
	else if (n < 10)
	{
		a = n % 10 + '0';
		*rt += write(1, &a, 1);
	}
	else
	{
		ft_putnbr(n / 10, rt);
		a = n % 10 + '0';
		*rt += write(1, &a, 1);
	}
}
