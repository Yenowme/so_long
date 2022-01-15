/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:18:43 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/01/15 16:49:37 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef s_solong	t_solong;

int		open_file(char *file);
void	*save_img_xml(t_solong *so_long, char *str);
void	put_img(t_solong *so_long, void *img_ptr, int x, int y);

#endif
