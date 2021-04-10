# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 13:27:26 by mkarkaus          #+#    #+#              #
#    Updated: 2021/04/10 17:46:03 by mkarkaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.phony = all clean fclean re rec

NAME = corewar

SRCS = srcs/*.c

LIBFT = ../libft/libft.a

SRC_FILES = corewar.c get_players.c validate_champ.c op.c flags.c
SRC_PATH = ./srcs/
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

FLAGS = -Wall -Werror -Wextra

OBJ = $(patsubst %.c, %.o, $(SRC_FILES))

OS := $(shell uname)
ifeq ($(OS), Linux)
	CLR_CODE = "\\e["
endif

ifeq ($(OS), Darwin)
	CLR_CODE = "\\x1b["
endif

GREEN = $(CLR_CODE)1;32m
RESET = $(CLR_CODE)0m

MAKE = make --no-print-directory

$(NAME):
	@echo "Compiling 'libft.a'"
	@$(MAKE) -C ../libft
	@echo "$(GREEN)Done$(RESET)\n"
	@echo "Compiling 'corewar'- executable"
	@gcc $(SRC) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Done$(RESET)\n"

all: $(NAME)

clean:
	@echo "Removing '.o'- files"
	@$(MAKE) clean -C ../libft
	@rm -f $(OBJ)
	@echo "$(GREEN)Done$(RESET)\n"

fclean: clean
	@echo "Removing 'corewar'- executable"
	@rm -f $(NAME)
	@$(MAKE) fclean -C ../libft
	@echo "$(GREEN)Done$(RESET)\n"

re:
	@$(MAKE) fclean
	@$(MAKE) re -C ../libft
	@echo "Compiling 'corewar'- executable"
	@gcc $(SRC) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Done$(RESET)\n"

rec:
	@echo "Removing 'corewar'- executable"
	@rm -f $(NAME)
	@echo "$(GREEN)Done$(RESET)\n"
	@echo "Compiling 'corewar'- executable"
	@gcc $(SRC) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Done$(RESET)\n"
