#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 15:06:24 by kpiacent          #+#    #+#              #
#    Updated: 2016/03/06 16:29:56 by kpiacent         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fillit
L_DIR = libs/libft
F_DIR = src
H_DIR = src
FILES = $(F_DIR)/main.c $(F_DIR)/move.c $(F_DIR)/pos.c $(F_DIR)/debug.c $(F_DIR)/print.c $(F_DIR)/solve.c

TMP = Makefile~  $(F_DIR)/header.h~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME)

$(NAME) :
		CC -o $(NAME) $(FLAGS) $(FILES) -I $(L_DIR) -L $(L_DIR) -lft

clean :
		rm -f $(TMP)

fclean : clean
		rm -f $(NAME)

test :
	./$(NAME)

re : fclean all