# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/09 14:18:14 by jcarmona          #+#    #+#              #
#    Updated: 2016/11/02 22:23:44 by jcarmona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

CC		= gcc

LFLAGS 	= $(LIB) $(INCLUDE) -lft

LIB		= -L include/

INCLUDE = -I include/

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address

SRC 	= src/

FILES	= read.c validate.c store.c solve.c utils.c

OBJS 	= $(FILES:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(addprefix src/, $(FILES)) $(INCLUDE) 
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME) 
	mv $(OBJS) obj/

clean:
	rm -rf $(addprefix obj/,$(OBJS))

fclean: clean
	rm -rf $(NAME)

re: fclean all
