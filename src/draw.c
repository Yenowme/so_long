/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:10:17 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/18 15:23:34 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	draw_tile(t_solong *so_long, int x, int y)
{
	int	dir;
	int	exit_state;

	exit_state = so_long->map.player.score == so_long->map.collect.col_cnt;
	dir = so_long->map.player.dir;
	put_img(so_long, so_long->map.tile_img.img, x, y);
	if (so_long->map.map[y][x] == '1')
		put_img(so_long, so_long->map.wall_img.img, x, y);
	if (so_long->map.map[y][x] == 'C')
		put_img(so_long, so_long->map.collect.img.img, x, y);
	if (so_long->map.map[y][x] == 'E')
		put_img(so_long, so_long->map.exit_img[exit_state].img, x, y);
	if (so_long->map.map[y][x] == 'P')
		put_img(so_long, so_long->map.player.img[dir].img, x, y);
}

int	show_map(t_solong *so_long)
{
	int	x;
	int	y;

	y = 0;
	while (y < so_long->map.rows)
	{
		x = 0;
		while (x < so_long->map.cols)
		{
			draw_tile(so_long, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
