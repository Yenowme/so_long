# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 18:54:27 by jeong-yena        #+#    #+#              #
#    Updated: 2022/01/11 19:42:45 by jeong-yena       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= so_long

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -f

LIBFT_DIR				= ./lib/libft/
LIBFT_FLAGS				= -L./$(LIBFT_DIR) -lft
LIBFT_FILE				= $(LIBFT_DIR)libft.a

INCS_DIR				= ./include/
SRCS_DIR				= ./src/
MLX_DIR					= ./mlx/

INCS					= -I include
MLX_FLAGS				= -lmlx -framework OpenGL -framework Appkit

SRC						=	*.c

SRCS					=	$(addprefix $(SRCS_DIR), $(SRC))
OBJS					=	$(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft -I $(INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re : clean all

PHONY	: all clean fclean re bonus
