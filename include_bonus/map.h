/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:47 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/18 14:45:04 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define DIR 4;

# define BOTTOM 0
# define RIGHT 1
# define TOP 2
# define LEFT 3

# define X 1
# define Y 0

typedef struct s_solong	t_solong;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}		t_img;

typedef struct s_bat
{
	int	x;
	int	y;
}		t_bat;

typedef struct s_bats
{
	int		bat_cnt;
	int		top;
	int		img_type;
	t_img	img[4];
	t_bat	*arr;
}		t_bats;
typedef struct s_collect
{
	int	x;
	int	y;
	int	is_touch;
}		t_collect;
typedef struct s_col
{
	int			col_cnt;
	int			top;
	t_img		img;
	t_collect	*col_arr;
}			t_col;
typedef struct s_player
{
	int		x;
	int		y;
	int		score;
	int		step;
	int		cnt;
	int		dir;
	t_img	img[4];
}		t_player;

typedef struct s_map
{
	char		**map;
	int			rows;
	int			cols;
	t_img		tile_img;
	t_img		wall_img;
	t_img		exit_img[2];
	t_col		collect;
	t_player	player;
	t_bats		bats;
	int			offset[4][2];
	int			is_escapable;
}				t_map;

void	valid_map(t_solong *so_long, int rd_line, char *line);
void	valid_extention(char *file, char *ext);
int		check_map_element(t_solong *so_long, char c);
void	map_parse(t_solong *so_long, char *file);
void	check_wall(t_solong *so_long, int row);
void	valid_map_element(t_solong *so_long);
void	parse_element(t_solong *so_long, int row);

#endif
