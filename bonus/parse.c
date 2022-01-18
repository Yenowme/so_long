/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:27:31 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/18 00:25:38 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	cnt_map_size(t_solong *so_long, char *file)
{
	char	*line;
	int		rd_line;
	int		gnl_rt;
	int		fd;

	fd = open_file(file);
	gnl_rt = get_next_line(fd, &line);
	so_long->map.rows = 0;
	so_long->map.cols = ft_strlen(line);
	while (gnl_rt > 0)
	{
		rd_line = ft_strlen(line);
		so_long->map.rows++;
		valid_map(so_long, rd_line, line);
		free(line);
		gnl_rt = get_next_line(fd, &line);
	}
	if (gnl_rt == -1)
		error_exit("file read err.\n");
	close(fd);
}

void	malloc_map(t_solong *so_long)
{
	int	i;

	so_long->map.map = (char **)malloc(sizeof(char *) * (so_long->map.rows));
	so_long->map.collect.col_arr = (t_collect *)malloc(sizeof(t_collect)
			* so_long->map.collect.col_cnt);
	so_long->map.bats.arr = (t_bat *)malloc(sizeof(t_bat)
			* so_long->map.bats.bat_cnt);
	i = 0;
	while (i < so_long->map.rows)
	{
		so_long->map.map[i] = (char *)malloc(sizeof(char)
				* (so_long->map.cols) + 1);
		i++;
	}
}

void	save_map(t_solong *so_long, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open_file(file);
	i = 0;
	while (i < so_long->map.rows)
	{
		if (get_next_line(fd, &line) == -1)
			error_exit("file read err.\n");
		ft_strlcpy(so_long->map.map[i], line, so_long->map.cols + 1);
		check_wall(so_long, i);
		parse_element(so_long, i);
		free(line);
		i++;
	}
	close(fd);
	valid_map_element(so_long);
}

void	map_parse(t_solong *so_long, char *file)
{
	valid_extention(file, MAP_EXTENTION);
	cnt_map_size(so_long, file);
	malloc_map(so_long);
	save_map(so_long, file);
}
