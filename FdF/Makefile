Makefile# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 16:08:48 by gsauvair          #+#    #+#              #
#    Updated: 2015/01/05 16:55:30 by gsauvair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c tab.c hook.c initiating.c draw.c halp.c
DEL = rm -f

OBJ = $(SRC:.c=.o)

LIB_DIR = ./libft/

MLX = -L/usr/X11/lib -lmlx -lXext -lX11

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)

	@echo " ______   _____     ______  "
	@echo "/\  ___\ /\  __-.  /\  ___\ "
	@echo "\ \  __\ \ \ \/\ \ \ \  __\ "
	@echo " \ \_\    \ \____-  \ \_\   "
	@echo "  \/_/     \/____/   \/_/   "
	@echo "                        glio"
	@cd $(LIB_DIR); $(MAKE) -f Makefile
	@gcc $(FLAG) -o $(NAME) $(OBJ) $(LIB_DIR)libft.a $(MLX)
	
clean:
	@$(DEL) $(OBJ)
	@cd $(LIB_DIR); $(MAKE) clean -f Makefile

fclean: clean
	@$(DEL) $(NAME)
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " |  ./fdf |"
	@echo " | deleted|"
	@echo " '--------'"
	@cd $(LIB_DIR); $(MAKE) fclean -f Makefile

re: fclean all
