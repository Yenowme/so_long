/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:48:50 by yejeong           #+#    #+#             */
/*   Updated: 2021/07/17 17:16:02 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n < 10)
	{
		a = n % 10 + '0';
		write(fd, &a, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		a = n % 10 + '0';
		write(fd, &a, 1);
	}
}
