# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/01 17:11:36 by gsauvair          #+#    #+#              #
#    Updated: 2015/03/01 19:45:40 by gsauvair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

CFLAGS = -Wall -Wextra -Werror -c

LFLAGS = -L libft -lft  -lncurses -lc

INC = -I includes/ -I libft/includes

LIB_DIR = ./libft/

SRCSDIR = ./srcs/

SRCS += keys.c loop.c main.c move.c print_tab.c refresh.c conditions_wl.c
SRCS += draw_norm_lol.c


OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(INC) -o  $(NAME) $(OBJ) $(LFLAGS)

$(OBJ): $(addprefix $(SRCSDIR),$(SRCS))
	make -C libft/
	gcc $(CFLAGS) $(INC) $(addprefix $(SRCSDIR),$(SRCS)) $(LFLAGS)

nof: 
	gcc -c $(INC) $(addprefix $(SRCSDIR),$(SRCS)) $(LFLAGS)
	gcc $(INC) $(NAME) $(OBJ) $(LFLAGS)


clean:
	rm -rf $(OBJ)
	@cd $(LIB_DIR); $(MAKE) clean -f Makefile

fclean: clean
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " |  2048  |"
	@echo " | deleted|"
	@echo " '--------'"
	rm -rf $(NAME)

re: fclean all

.PHONY: make all fclean re nof