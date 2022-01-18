/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeong <yejeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:58:58 by yejeong           #+#    #+#             */
/*   Updated: 2021/05/26 17:20:39 by yejeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 400
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);

int		get_next_line(int fd, char **line);

#endif
