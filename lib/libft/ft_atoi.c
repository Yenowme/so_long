/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeong <yejeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:36:23 by yejeong           #+#    #+#             */
/*   Updated: 2021/05/16 19:31:55 by yejeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned long	atoi_sub(const char *str)
{
	int				i;
	unsigned long	rt;

	rt = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rt += (int)str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			rt *= 10;
		i++;
	}
	return (rt);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sum;
	unsigned long	rt;

	sum = 1;
	i = 0;
	rt = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sum = -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
		rt = atoi_sub(&str[i]);
	if (sum == 1 && rt > 9223372036854775807)
		return (-1);
	else if (sum == -1 && rt > 9223372036854775807)
		return (0);
	return ((int)rt * sum);
}
