# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 11:35:45 by sreijola          #+#    #+#              #
#    Updated: 2021/04/03 13:09:50 by sreijola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = sreijola.filler

SRCS_ASM = main.c

LIB = ../libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(ASM_SRCS) $(FLAGS) $(LIB) -o $(ASM)
	@echo "$(ASM) made"

clean:
	@make -C libft clean
	@echo "Object files removed from libft. Beep-Bop"

fclean: clean
	@make -C libft fclean
	@rm -f $(ASM)
	@echo "Binaries and object files gone."

re: fclean all
	@echo "All good again"
