# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 13:13:02 by agouby            #+#    #+#              #
#    Updated: 2017/09/19 22:41:43 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP_LIB = n
CC = gcc
CFLA = -Wall -Werror -Wextra  
NAME = lem-in
INC = -I./includes
INC_LIB = -I./libft/includes
LIB_PATH = -L./libft -lftprintf
SRC = $(shell find ./srcs | grep "\.c$$")
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
ifeq ($(COMP_LIB), y)
	@make -C libft
endif
	@$(CC) $(CFLA) $(CHELP) -o $(NAME) $(OBJ) $(LIB_PATH)

%.o: %.c
	@printf "\rCompiling $<"
	@$(CC) $(CFLA) $(INC) $(INC_LIB) -c $< -o $@

clean:
ifeq ($(COMP_LIB), y)
	@make clean -C libft
endif
	@/bin/rm -f $(OBJ)
fclean: clean
ifeq ($(COMP_LIB), y)
	@make fclean -C libft
endif
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
