# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 18:54:27 by jeong-yena        #+#    #+#              #
#    Updated: 2022/01/18 22:08:07 by jeong-yena       ###   ########.fr        #
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

SRC						= main.c parse.c utils.c validator.c set_mlx.c event.c parse_element.c draw.c
SRCS					= $(addprefix $(SRCS_DIR), $(SRC))
OBJS					= $(SRCS:.c=.o)

BONUS_NAME				= so_long_bonus
BONUS_DIR				= ./bonus/
BONUS_INCS_DIR			= ./include_bonus/
BONUS_SRC				= main_bonus.c parse_bonus.c utils_bonus.c validator_bonus.c set_mlx_bonus.c \
						event_bonus.c parse_element_bonus.c draw_bonus.c
BONUS_SRCS				= $(addprefix $(BONUS_DIR), $(BONUS_SRC))
BONUS_OBJS				= $(BONUS_SRCS:.c=.o)

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
	make -C $(GNL_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(BONUS_OBJS) a.out.dSYM

fclean : clean
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	$(RM) $(NAME) $(BONUS_OBJS) $(BONUS_NAME) a.out.dSYM

re : fclean all

bonus_re : fclean bonus

test :
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	$(CC) -g -o $(NAME) $(SRCS) $(GNL_FLAGS) $(LIBFT_FLAGS) -I $(INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

leak :
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	$(CC) -g3 -fsanitize=address -o $(NAME) $(SRCS) $(GNL_FLAGS) $(LIBFT_FLAGS) -I $(INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(BONUS_NAME) $(BONUS_OBJS) $(GNL_FLAGS) $(LIBFT_FLAGS) -I $(BONUS_INCS_DIR) -L $(MLX_DIR) $(MLX_FLAGS)

norm :
	norminette $(SRCS) $(BONUS_SRCS) $(INCS_DIR)*.h $(BONUS_INCS_DIR)*.h

PHONY	: all clean fclean re bonus
