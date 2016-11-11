# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/09 14:18:14 by jcarmona          #+#    #+#              #
#    Updated: 2016/11/10 16:07:44 by wlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

CC		= gcc

LIB		= -L incl/

INCLUDE = -I incl/

CFLAGS	= -Wall -Wextra -Werror

SRC 	= srcs/

FILES	= fillit.c read.c validate.c store.c solve.c utils.c map_gen.c place.c utilstwo.c

OBJS 	= $(FILES:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(addprefix srcs/, $(FILES)) $(INCLUDE) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 
	mkdir objs/
	mv $(OBJS) objs/

clean:
	rm -rf objs/

fclean: clean
	rm -rf $(NAME)

re: fclean all
