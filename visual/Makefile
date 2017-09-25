# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/20 12:30:24 by agouby            #+#    #+#              #
#    Updated: 2017/09/22 23:00:22 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../visual.fx
CC = gcc -g
FLA = -Wall -Werror -Wextra
INC = -I./includes
INC_LIB = -I../libft/includes
INC_MLX_MAC = -I./minilibx_macos
INC_MLX_LIN = -I./minilibx_X11

LIB_MLX_MAC = -L./minilibx_macos -lmlx
LIB_MLX_LIN = -L./minilibx_X11 -lmlx

MLX_FLA_MAC = -framework OpenGL -framework AppKit
MLX_FLA_LIN = -lX11 -lXext

LIB_PATH = -L../libft -lftprintf
SRC = $(shell find ./srcs | grep "\.c$$")
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx_X11
	@$(CC) $(FLA) -o $(NAME) $(OBJ) $(LIB_PATH) $(LIB_MLX_LIN) $(MLX_FLA_LIN)

	#@$(CC) $(FLA) -o $(NAME) $(OBJ) $(LIB_PATH) $(INC_MLX_MAC) $(LIB_MLX_MAC) $(MLX_FLA_MAC)

%.o: %.c
	@$(CC) $(FLA) $(INC) $(INC_LIB) $(INC_MLX_LIN) -c $< -o $@

clean:
	@/bin/rm -f minilibx_X11/*.o
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f minilibx_X11/*.a
	@/bin/rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re
