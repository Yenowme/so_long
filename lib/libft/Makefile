# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 19:05:29 by jeong-yena        #+#    #+#              #
#    Updated: 2022/01/11 19:05:54 by jeong-yena       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	=	ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
  			ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
  			ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
  			ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
  			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
  			ft_tolower.c ft_toupper.c ft_bzero.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_atoi.c ft_calloc.c ft_putchar.c \
			ft_putstr.c ft_putnbr.c ft_putun.c \
			ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
			ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS	= $(SRCS:.c=.o)
OBJS_FILES = $(OBJS)
OBJS_B	= $(BOUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS_FILES)
	ar rcs $@ $(OBJS_FILES)

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: clean fclean re all bonus
