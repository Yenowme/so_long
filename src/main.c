/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:02:08 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/17 16:48:54 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_ERR);
}

void	init_solong(t_solong *so_long)
{
	ft_bzero(so_long, sizeof(t_solong));
	so_long->map.offset[TOP][Y] = -1;
	so_long->map.offset[BOTTOM][Y] = +1;
	so_long->map.offset[LEFT][X] = -1;
	so_long->map.offset[RIGHT][X] = 1;
}

void	draw_tile(t_solong *so_long, int x, int y)
{
	int	dir;

	dir = so_long->map.player.dir;
	put_img(so_long, so_long->map.tile_img.img, x, y);
	if (so_long->map.map[y][x] == '1')
		put_img(so_long, so_long->map.wall_img.img, x, y);
	if (so_long->map.map[y][x] == 'C')
		put_img(so_long, so_long->map.collect.img.img, x, y);
	if (so_long->map.map[y][x] == 'E')
		put_img(so_long, so_long->map.exit_img.img, x, y);
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

int	main(int argc, char **argv)
{
	t_solong	so_long;

	if (argc != 2)
		error_exit("Use one .ber file\n");
	init_solong(&so_long);
	map_parse(&so_long, argv[1]);
	set_mlx(&so_long);
	mlx_hook(so_long.win, 2, 0, &key_event, &so_long);
	mlx_loop_hook(so_long.mlx, &show_map, &so_long);
	mlx_loop(so_long.mlx);
}
