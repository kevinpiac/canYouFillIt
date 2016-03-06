#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 15:06:24 by kpiacent          #+#    #+#              #
#    Updated: 2016/03/06 14:01:00 by kpiacent         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fillit
L_DIR = libs/libft
F_DIR = src
H_DIR = libs/libft/
FILES = $(F_DIR)/main.c

TMP = Makefile~  header.h~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME)

$(NAME) :
		CC -o $(NAME) $(FLAGS) $(FILES) -I $(H_DIR) -L $(L_DIR) -lft

clean :
		rm -f $(TMP)

fclean : clean
		rm -f $(NAME)

re : fclean all