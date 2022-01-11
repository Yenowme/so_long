/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:27:31 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/11 18:49:41 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	is_map_valid(char *file)
{
	//확장자 체크
	//출구 체크
}

void	map_parse(t_solong so_long, char *file)
{
	int	fd;

	if(!is_map_valid(file))
	{
		error_exit("Map is not valid");
	}
}
