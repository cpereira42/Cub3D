# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 16:29:40 by cpereira          #+#    #+#              #
#    Updated: 2021/02/17 14:50:22 by cpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			cub3D

HEADER_DIR =	includes
SRC_DIR =		src
OBJ_DIR	=		.obj

LIBFT_DIR =		libft
LIBFT =			$(LIBFT_DIR)/libft.a

MLX_LINUX_DIR =	minilibx

MLX_LINUX =	$(MLX_LINUX_DIR)/libmlx.a

SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/botoes.c \
		$(SRC_DIR)/calculos.c \
		$(SRC_DIR)/carrega.c \
		$(SRC_DIR)/colisoes.c \
		$(SRC_DIR)/erros.c \
		$(SRC_DIR)/extras.c \
		$(SRC_DIR)/extras2.c \
		$(SRC_DIR)/extras3.c \
		$(SRC_DIR)/alocacao.c \
		$(SRC_DIR)/ajustadores.c \
		$(SRC_DIR)/get_next_line.c \
		$(SRC_DIR)/get_next_line_utils.c \
		$(SRC_DIR)/sprits.c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

HEADER_LINUX =	-I./$(HEADER_DIR) -I./$(MLX_LINUX_DIR) -I./$(LIBFT_DIR)

CFLAGS = -Wall -Wextra -Werror

LINUX_FLAGS = -lXext -lX11 -lbsd -lm -lmlx \
				-L ./$(LIBFT_DIR) -lft \
				-L ./$(MLX_LINUX_DIR) -lmlx

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LINUX)
		clang $(OBJ) $(HEADER_LINUX) $(CFLAGS) $(LINUX_FLAGS) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
				mkdir -p $(OBJ_DIR)
				clang -c $(CFLAGS) $(HEADER_LINUX) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX_LINUX):
	make -C $(MLX_LINUX_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	/bin/rm -f $(NAME) ./libmlx.dylib

re: fclean all

.PONY: all clean fclean re mac
