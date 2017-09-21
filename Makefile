# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 13:13:02 by agouby            #+#    #+#              #
#    Updated: 2017/09/21 21:36:14 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP_LIB = n
NAME = lem-in
CC = gcc
CFLA = -Wall -Werror -Wextra
INC = -I./includes
INC_LIB = -I./libft/includes
LIB_PATH = -L./libft -lftprintf
SRC = $(shell find ./srcs | grep "\.c$$")
SRC_V = $(shell find ./visual | grep "\.c$$")
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(SRC_V)
ifeq ($(COMP_LIB), y)
	@make -C libft
endif
	@make -C visual
	@$(CC) $(CFLA) -o $(NAME) $(OBJ) $(LIB_PATH)

%.o: %.c
	@printf "\rCompiling $<"
	@$(CC) $(CFLA) $(INC) $(INC_LIB) -c $< -o $@

clean:
ifeq ($(COMP_LIB), y)
	@make clean -C libft
endif
	@make clean -C visual
	@/bin/rm -f $(OBJ)
fclean: clean
ifeq ($(COMP_LIB), y)
	@make fclean -C libft
endif
	@make fclean -C visual
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
