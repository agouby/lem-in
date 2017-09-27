# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/20 12:30:24 by agouby            #+#    #+#              #
#    Updated: 2017/09/26 16:20:44 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../visual.fx
CC = gcc
FLA = -Wall -Werror -Wextra
INC = -I./includes
INC_LIB = -I../libft/includes
INC_MLX_MAC = -I./minilibx_macos
LIB_MLX_MAC = -L./minilibx_macos -lmlx
MLX_FLA_MAC = -framework OpenGL -framework AppKit

LIB_PATH = -L../libft -lftprintf
SRC = $(shell find ./srcs | grep "\.c$$")
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx_macos
	@$(CC) $(FLA) -o $(NAME) $(OBJ) $(LIB_PATH) $(INC_MLX_MAC) $(LIB_MLX_MAC) $(MLX_FLA_MAC)

%.o: %.c
	@$(CC) $(FLA) $(INC) $(INC_LIB) $(INC_MLX_MAC) -c $< -o $@

clean:
	@/bin/rm -f minilibx_macos/*.o
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f minilibx_macos/*.a
	@/bin/rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re
