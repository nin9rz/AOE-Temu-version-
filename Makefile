# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llinares <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 21:39:21 by llinares          #+#    #+#              #
#    Updated: 2024/12/13 22:18:10 by llinares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AOE_temu

CC = gcc

SOURCES = $(shell find src -name '*.c')

LIB = lib/raylib/src/libraylib.a

OBJECTS = $(SOURCES:.c=.o)

INCLUDES = include

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIB) -o $(NAME) -lm -I$(INCLUDES)

%.o: %.c
	$(CC) -c $< -o $@ -I$(INCLUDES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
