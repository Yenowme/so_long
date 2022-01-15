/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:18:11 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/15 19:41:06 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		error_exit("File open err\n");
	return (fd);
}

void	*save_img_xml(t_solong *so_long, char *str)
{
	char	*path;
	void	*rt;
	int		width;
	int		height;

	path = ft_strjoin(IMG_PATH, str);
	rt = mlx_xpm_file_to_image(so_long->mlx, path, &width, &height);
	if (!rt)
		error_exit("Failed to save img");
	free(path);
	return (rt);
}

void	put_img(t_solong *so_long, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx, so_long->win,
		img_ptr, x * IMG_PX, y * IMG_PX);
}
