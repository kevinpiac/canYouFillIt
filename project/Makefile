#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 15:06:24 by kpiacent          #+#    #+#              #
#    Updated: 2016/03/15 16:42:55 by kpiacent         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fillit
L_DIR = libs/libft
F_DIR = src
H_DIR = src
FILES = $(F_DIR)/main.c $(F_DIR)/move.c $(F_DIR)/pos.c $(F_DIR)/debug.c $(F_DIR)/print.c $(F_DIR)/solve.c $(F_DIR)/check.c $(F_DIR)/read.c

TMP = Makefile~  $(F_DIR)/header.h~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME)

$(NAME) :
		@CC -o $(NAME) $(FLAGS) $(FILES) -I $(L_DIR) -L $(L_DIR) -lft
		@echo "Complilation: \t\t\tDONE!"

clean :
		@rm -f $(TMP)
		@echo "Cleaning: \t\t\tDONE!"

fclean : clean
		@rm -f $(NAME)
		@echo "Remove the exec: \t\tDONE!"
test :
	./$(NAME)

re : fclean all