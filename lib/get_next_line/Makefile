# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 16:08:55 by jeong-yena        #+#    #+#              #
#    Updated: 2022/01/12 17:33:20 by jeong-yena       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libgnl.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= get_next_line.c get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $(OBJS)

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

test :
	gcc -g $(SRCS) main.c -I ./

leak :
	gcc -g3 -fsanitize=address $(SRCS) -I ./

.PHONY: clean fclean re all bonus test
