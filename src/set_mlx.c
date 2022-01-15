/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:59:12 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/15 20:21:15 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	set_window(t_solong *so_long)
{
	int	width;
	int	height;

	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		error_exit("Failed to mlx_init\n");
	width = so_long->map.cols * IMG_PX;
	height = so_long->map.rows * IMG_PX;
	so_long->win = mlx_new_window(so_long->mlx, width, height, "so_long");
	if (!so_long->win)
		error_exit("Failed to init_window \n");
}

static void	set_img(t_solong *so_long)
{
	so_long->map.tile_img.img = save_img_xml(so_long, "tile.xpm");
	so_long->map.wall_img.img = save_img_xml(so_long, "wall.xpm");
	so_long->map.exit_img.img = save_img_xml(so_long, "exit.xpm");
	so_long->map.player.img[TOP].img = save_img_xml(so_long, "cat_top.xpm");
	so_long->map.player.img[BOTTOM].img = save_img_xml(so_long, "cat_bot.xpm");
	so_long->map.player.img[LEFT].img = save_img_xml(so_long, "cat_left.xpm");
	so_long->map.player.img[RIGHT].img = save_img_xml(so_long, "cat_right.xpm");
	so_long->map.collect.img.img = save_img_xml(so_long, "collect.xpm");
}

void	set_mlx(t_solong *so_long)
{
	set_window(so_long);
	set_img(so_long);
}
