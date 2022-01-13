/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:47 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/13 20:12:03 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_solong	t_solong;

typedef struct s_collect
{
	int	idx;
	int	x;
	int	y;
	int	is_touch;
}		t_collect;
typedef struct s_col
{
	int			col_cnt;
	int			top;
	t_collect	*col_arr;
}			t_col;
typedef struct s_player
{
	int	x;
	int	y;
	int	score;
	int	cnt;
}		t_player;

typedef struct s_map
{
	char		**map;
	int			rows;
	int			cols;
	t_col		collect;
	t_player	player;
	int			is_escapable;
}				t_map;

void	valid_map(t_solong *so_long, int rd_line, char *line);
void	valid_extention(char *file, char *ext);
int		check_map_element(t_solong *so_long, char c);
void	map_parse(t_solong *so_long, char *file);
void	check_wall(t_solong *so_long, int row);
void	valid_map_element(t_solong *so_long);
#endif
