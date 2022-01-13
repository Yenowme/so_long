/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:03 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/12 21:44:07 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_map_asset(char c)
{
	return ((c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'E'));
}

void	valid_extention(char *file, char *ext)
{
	int	file_ext;

	file_ext = ft_strlen(file) - ft_strlen(ext);
	while (file_ext < (int)ft_strlen(file))
	{
		if (file[file_ext] != *ext)
			error_exit("The file extension should be \".ber\".\n");
		ext++;
		file_ext++;
	}
}

int	valid_map_check_exit(t_solong *so_long, int rd_line, char *line)
{
	int	is_exit;

	is_exit = FALSE;
	if (rd_line != so_long->map.cols)
		error_exit("map is not rectangular.\n");
	while (--rd_line >= 0)
	{
		if (!is_valid_map_asset(line[rd_line]))
			error_exit("Invalid element on map.\n");
		if (line[rd_line] == 'E')
			is_exit = TRUE;
	}
	return (is_exit);
}
