/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:12:49 by yejeong           #+#    #+#             */
/*   Updated: 2022/01/12 17:15:24 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_tmp(char **tmp, char **line)
{
	char	*end;
	char	*buff;

	if (!*tmp)
		*tmp = ft_strdup("");
	end = ft_strchr(*tmp, '\n');
	if (end)
	{
		*end = 0;
		buff = *tmp;
		*line = ft_strdup(*tmp);
		*tmp = ft_strdup(end + 1);
		free(buff);
		return (1);
	}
	return (0);
}

static int	check_line(char **tmp, char **line)
{
	char	*end;
	char	*buff;

	end = ft_strchr(*line, '\n');
	if (end)
	{
		*end = 0;
		buff = *line;
		if (*tmp)
			*line = ft_strjoin(*tmp, *line);
		*tmp = ft_strdup(end + 1);
		free(buff);
		return (1);
	}
	else if (!*tmp)
		*tmp = ft_strdup(*line);
	else
		*tmp = ft_strjoin(*tmp, *line);
	return (0);
}

int	read_line(int fd, char **line, char **tmp)
{
	int			rd_size;
	int			rt;

	rt = 1;
	rd_size = read(fd, *line, BUFFER_SIZE);
	if (rd_size == -1)
		return (-1);
	while (rd_size > 0)
	{
		(*line)[rd_size] = 0;
		rt = check_line(tmp, line);
		if (rt)
			return (rt);
		rd_size = read(fd, *line, BUFFER_SIZE);
		if (rd_size == -1)
			return (-1);
	}
	if (!rt)
		return (rt);
	free(*line);
	*line = tmp[fd];
	tmp[fd] = 0;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*tmp[OPEN_MAX];
	int			rt;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || fd > OPEN_MAX
		|| read(fd, *line, 0) == -1)
		return (-1);
	rt = check_tmp(&tmp[fd], line);
	if ((rt))
		return (rt);
	*line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*line)
		return (-1);
	rt = read_line(fd, line, &tmp[fd]);
	return (rt);
}
