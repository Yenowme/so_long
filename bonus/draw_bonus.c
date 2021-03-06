/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:10:17 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/18 18:07:32 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

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
	if (so_long->map.map[y][x] == 'B')
		put_img(so_long,
			so_long->map.bats.img[so_long->map.bats.img_type].img, x, y);
}

void	draw_step(t_solong *so_long)
{
	char	*str;

	str = ft_itoa(so_long->map.player.step);
	mlx_put_image_to_window(so_long->mlx, so_long->win,
		so_long->step_back.img, STEP_OFFSET, STEP_OFFSET);
	mlx_string_put(so_long->mlx, so_long->win, 10, 20, 0xFF3D48, str);
	free(str);
}

int	show_map(t_solong *so_long)
{
	int	x;
	int	y;

	if (so_long->frame == FRAME)
	{
		so_long->frame = 0;
		so_long->map.bats.img_type++;
		if (so_long->map.bats.img_type == 4)
			so_long->map.bats.img_type = 0;
	}
	so_long->frame++;
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
	draw_step(so_long);
	return (0);
}
