# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/06 02:00:45 by qhusler           #+#    #+#              #
#    Updated: 2016/11/19 16:08:24 by qhusler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = ./includes/
SRCS = main.c	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $< -o $@ -I $(INCLUDES) -L./libft -lft
	@echo [ compiling ] [ $< ]

%.o: %.c
	@$(CC) $(CFLAGS) -c $< 
	@echo [ compiling ] [ $< ]

#-I $(INCLUDES) -L./libft -lft

clean:
	rm -f $(OBJS)
	

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
