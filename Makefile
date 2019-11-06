# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 13:20:27 by bbellavi          #+#    #+#              #
#    Updated: 2019/11/06 13:29:27 by bbellavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= get_next_line
DEP		= get_next_line.c get_next_line_utils.c
INCLUDE = .
.PHONY:	all fclean clean re

all: $(NAME)

$(NAME): $(DEP)
	$(CC) $(CFLAGS) -o $(NAME) $? -I$(INCLUDE) -D BUFFER_SIZE=1000

clean:
	rm -rf $(NAME) $(NAME).dSYM

re: clean all