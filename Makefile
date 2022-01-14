# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 18:54:27 by jeong-yena        #+#    #+#              #
#    Updated: 2022/01/14 19:50:19 by jeong-yena       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= so_long

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -f

LIBFT_DIR				= ./lib/libft/
LIBFT_FLAGS				= -L ./$(LIBFT_DIR) -lft
LIBFT_FILE				= $(LIBFT_DIR)libft.a

GNL_DIR					= ./lib/get_next_line/
GNL_FLAGS				= -L ./$(GNL_DIR) -lgnl
GNL_FILE				= $(LIBFT_DIR)libgnl.a

INCS_DIR				= ./include/
SRCS_DIR				= ./src/
MLX_DIR					= ./mlx/

INCS					= -I include
MLX_FLAGS				= -lmlx -framework OpenGL -framework Appkit

SRC						= main.c parse.c utils.c validator.c
SRCS					= $(addprefix $(SRCS_DIR), $(SRC))
OBJS					= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) $(GNL_FLAGS) $(LIBFT_FLAGS) -I $(INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS) a.out.dSYM

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS) a.out.dSYM

re : fclean all

test :
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	$(CC) -g -o $(NAME) $(SRCS) $(GNL_FLAGS) $(LIBFT_FLAGS) -I $(INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

PHONY	: all clean fclean re bonus
