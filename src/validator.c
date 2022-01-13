/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:03 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/13 19:26:57 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_element(t_solong *so_long, char c)
{
	if ((c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E'))
		return (FALSE);
	if (c == 'C')
		so_long->map.collect.col_cnt++;
	else if (c == 'P')
		so_long->map.player.cnt++;
	else if (c == 'E')
		so_long->map.is_escapable = TRUE;
	return (TRUE);
}

void	valid_extention(char *file, char *ext)
{
	int	i;

	i = ft_strlen(file) - ft_strlen(ext);
	while (i < (int)ft_strlen(file))
	{
		if (file[i] != *ext)
			error_exit("The file extension should be \".ber\".\n");
		ext++;
		i++;
	}
}

void	valid_map(t_solong *so_long, int rd_line, char *line)
{
	if (rd_line != so_long->map.cols)
		error_exit("map is not rectangular.\n");
	while (--rd_line >= 0)
	{
		if (!check_map_element(so_long, line[rd_line]))
			error_exit("Invalid element on map.\n");
	}
}

void	check_wall(t_solong *so_long, int row)
{
	int		i;
	char	*line;

	line = so_long->map.map[row];
	i = 0;
	if (row == 0 || row == so_long->map.rows - 1)
	{
		while (line[i])
		{
			if (line[i] != '1')
				error_exit("map must be surrounded by walls\n");
			i++;
		}
	}
	else
	{
		if (line[0] != '1' || line[so_long->map.cols - 1] != '1')
			error_exit("map must be surrounded by walls\n");
	}
}

void	valid_map_element(t_solong *so_long)
{
	if (so_long->map.collect.col_cnt <= 0)
		error_exit("map must have at least one collector\n");
	if (so_long->map.is_escapable == FALSE)
		error_exit("map must have at least one exit\n");
	if (so_long->map.player.cnt != 1)
		error_exit("map must have one starting position\n");
}
