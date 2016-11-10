# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/09 14:18:14 by jcarmona          #+#    #+#              #
#    Updated: 2016/11/09 21:36:10 by jcarmona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

CC		= gcc

LFLAGS 	= $(LIB) $(INCLUDE) -lft

LIB		= -L incl/

INCLUDE = -I incl/

CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address

SRC 	= srcs/

FILES	= fillit.c read.c validate.c store.c solve.c utils.c map_gen.c place.c

OBJS 	= $(FILES:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(addprefix srcs/, $(FILES)) $(INCLUDE) 
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME) 
	mkdir objs/
	mv $(OBJS) objs/

clean:
	rm -rf objs/

fclean: clean
	rm -rf $(NAME)

re: fclean all
