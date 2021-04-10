# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 11:35:45 by sreijola          #+#    #+#              #
#    Updated: 2021/04/10 18:58:23 by sreijola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = asm

ASM_SRCS = main.c get_input.c write_bytecode.c

LIB = ../libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C ../libft
	@gcc $(ASM_SRCS) $(FLAGS) $(LIB) -o $(NAME)
	@echo "$(ASM) made"

clean:
	@make -C ../libft clean
	@echo "Object files removed from libft. Beep-Bop"

fclean: clean
	@make -C ../libft fclean
	@rm -f $(NAME)
	@echo "Binaries and object files gone."

re: fclean all
	@echo "All good again"
