/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:25:41 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/18 00:37:57 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	set_collect(t_solong *so_long, int y, int x)
{
	int	top;

	top = so_long->map.collect.top;
	so_long->map.collect.col_arr[top].x = x;
	so_long->map.collect.col_arr[top].y = y;
	so_long->map.collect.col_arr[top].is_touch = FALSE;
	so_long->map.collect.top++;
}

static void	set_bat(t_solong *so_long, int y, int x)
{
	int	top;

	top = so_long->map.bats.top;
	so_long->map.bats.arr[top].x = x;
	so_long->map.bats.arr[top].y = y;
	so_long->map.bats.top++;
}

static void	set_player(t_solong *so_long, int y, int x)
{
	so_long->map.player.x = x;
	so_long->map.player.y = y;
}

void	parse_element(t_solong *so_long, int row)
{
	char	*line;
	int		i;

	i = 0;
	line = so_long->map.map[row];
	while (i < so_long->map.cols)
	{
		if (line[i] == 'C')
			set_collect(so_long, row, i);
		if (line[i] == 'P')
			set_player(so_long, row, i);
		if (line[i] == 'B')
			set_bat(so_long, row, i);
		i++;
	}
}
