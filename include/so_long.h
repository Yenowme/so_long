/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:36:13 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/11 19:03:06 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>

# include "../mlx/mlx.h"
# include "../lib/libft/libft.h"

# define TURE	1
# define FALSE	0

# define EXIT_ERR 1

typedef struct s_map
{
	char	**map;
	char	*file;
	int		rows;
	int		cols;
}				t_map;

typedef struct s_solong
{
	void	*mlx;
	void	*win;
	t_map	map;
}				t_solong;

void	error_exit(char *str);

#endif
