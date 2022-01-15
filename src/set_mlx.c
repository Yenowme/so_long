/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:59:12 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/15 19:31:34 by jeong-yena       ###   ########.fr       */
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
	so_long->map.tile_img = save_img_xml(so_long, "tile.xpm");
}

void	set_mlx(t_solong *so_long)
{
	set_window(so_long);
	set_img(so_long);
}
