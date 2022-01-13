/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:47 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/12 22:09:38 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_solong	t_solong;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
}				t_map;

int		valid_map_check_exit(t_solong *so_long, int rd_line, char *line);
void	valid_extention(char *file, char *ext);
int		is_valid_map_asset(char c);
void	map_parse(t_solong *so_long, char *file);

#endif
