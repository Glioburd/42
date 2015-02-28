# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/01 17:11:36 by gsauvair          #+#    #+#              #
#    Updated: 2015/02/28 17:43:24 by gsauvair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

SRC = ./srcs/main.c ./srcs/draw_grid.c ./srcs/exit.c ./srcs/grid.c
DEL = rm -f

OBJ = $(SRC:.c=.o)

LIB_DIR = ./libft/

NCURSES = -lncurses

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@cd $(LIB_DIR); $(MAKE) -f Makefile
	@gcc $(FLAG) -o $(NAME) $(OBJ) $(LIB_DIR)libft.a $(NCURSES)
	@echo "\033[1;37m"
	@echo "FDF"

clean:
	@$(DEL) $(OBJ)
	@cd $(LIB_DIR); $(MAKE) clean -f Makefile

fclean: clean
	@$(DEL) $(NAME)
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " |  2048  |"
	@echo " | deleted|"
	@echo " '--------'"
	@cd $(LIB_DIR); $(MAKE) fclean -f Makefile

re: fclean all
