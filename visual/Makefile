# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/20 12:30:24 by agouby            #+#    #+#              #
#    Updated: 2017/09/20 16:15:05 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../visual.fx
CC = gcc
FLA = -Wall -Werror -Wextra
INC = -I./includes
INC_LIB = -I../libft/includes
INC_MLX = -I./minilibx_macos
LIB_MLX = -L./minilibx_macos -lmlx
MLX_FLA = -framework OpenGL -framework AppKit
LIB_PATH = -L../libft -lftprintf
SRC = $(shell find ./srcs | grep "\.c$$")
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLA) -o $(NAME) $(OBJ) $(LIB_PATH) $(INC_MLX) $(LIB_MLX) $(MLX_FLA)

%.o: %.c
	@$(CC) $(FLA) $(INC) $(INC_LIB) -c $< -o $@

clean:
	@/bin/rm -f minilibx_macos/*.o
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f minilibx_macos/libmlx.a
	@/bin/rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re
