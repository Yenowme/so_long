/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:01:44 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/18 14:42:09 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	find_collect(t_solong *so_long, int x, int y)
{
	t_collect	target;
	int			i;

	i = 0;
	while (i < so_long->map.collect.col_cnt)
	{
		if (so_long->map.collect.col_arr[i].x == x
			&& so_long->map.collect.col_arr[i].y == y)
			target = so_long->map.collect.col_arr[i];
		i++;
	}
	if (!target.is_touch)
	{
		target.is_touch = TRUE;
		so_long->map.player.score++;
	}
}

static void	check_exit(t_solong *so_long)
{
	if (so_long->map.player.score == so_long->map.collect.col_cnt)
	{
		printf("=========game clear========\n");
		exit(0);
	}
}

static int	check_new_player(t_solong *so_long)
{
	int	x;
	int	y;

	x = so_long->map.player.x;
	y = so_long->map.player.y;
	if (so_long->map.map[y][x] == '1')
		return (FALSE);
	if (so_long->map.map[y][x] == 'C')
		find_collect(so_long, x, y);
	if (so_long->map.map[y][x] == 'E')
	{
		check_exit(so_long);
		return (FALSE);
	}
	if (so_long->map.map[y][x] == 'B')
	{
		printf("======game over========\n");
		exit(0);
	}
	return (TRUE);
}

static void	move_player(t_solong *so_long, int dir)
{
	int	x;
	int	y;

	x = so_long->map.player.x;
	y = so_long->map.player.y;
	so_long->map.player.dir = dir;
	so_long->map.player.x = x + so_long->map.offset[dir][X];
	so_long->map.player.y = y + so_long->map.offset[dir][Y];
	if (!check_new_player(so_long))
	{
		so_long->map.player.x = x;
		so_long->map.player.y = y;
		return ;
	}
	so_long->map.map[y][x] = '0';
	so_long->map.map[so_long->map.player.y][so_long->map.player.x] = 'P';
	so_long->map.player.step++;
	printf("player step : %d \n", so_long->map.player.step);
}

int	key_event(int key_code, t_solong *so_long)
{
	if (key_code == KEY_ESC)
		close_solong(so_long);
	if (key_code == KEY_W)
		move_player(so_long, TOP);
	if (key_code == KEY_A)
		move_player(so_long, LEFT);
	if (key_code == KEY_D)
		move_player(so_long, RIGHT);
	if (key_code == KEY_S)
		move_player(so_long, BOTTOM);
	return (0);
}
