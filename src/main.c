/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:02:08 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/12 17:27:25 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_solong	so_long;

	if (argc != 2)
		error_exit("Use one .ber file\n");
	map_parse(&so_long, argv[1]);
}
