/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:36:13 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/12 21:35:24 by jeong-yena       ###   ########.fr       */
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

# include "./utils.h"
# include "./map.h"

# define TRUE	1
# define FALSE	0

# define EXIT_ERR 1
# define MAP_EXTENTION ".ber"

typedef struct s_map	t_map;
typedef struct s_solong
{
	void	*mlx;
	void	*win;
	t_map	map;
}				t_solong;

void	error_exit(char *str);

#endif
