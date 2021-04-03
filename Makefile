# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 11:35:45 by sreijola          #+#    #+#              #
#    Updated: 2021/04/03 13:15:40 by sreijola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re asm cw

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all:
	@make -C libft
	@make -C asm
	@make -C corewar
	@echo "Library, asm and corewar made"

asm:
	@make -C asm

cw:
	@make -C corewar

clean:
	@make -C libft clean
	@echo "Object files removed from libft. Beep-Bop"

fclean: clean
	@make -C libft fclean
	@rm
	@echo "Binaries and object files gone."

re: fclean all
	@echo "All good again"
