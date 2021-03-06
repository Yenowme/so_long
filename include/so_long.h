/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:36:13 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/18 17:44:03 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# include "../mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"

# include "./map.h"
# include "./utils.h"

# define TRUE	1
# define FALSE	0

# define EXIT_ERR 1
# define MAP_EXTENTION ".ber"

# define IMG_PX 64
# define IMG_PATH "./img/"

# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_UP				126
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124

# define FRAME				15

typedef struct s_map	t_map;
typedef struct s_solong
{
	void	*mlx;
	void	*win;
	int		game_clear;
	t_map	map;
}				t_solong;

void	error_exit(char *str);
void	set_mlx(t_solong *so_long);
int		close_solong(t_solong *so_long);

int		key_event(int key_code, t_solong *so_long);
int		show_map(t_solong *so_long);

#endif
