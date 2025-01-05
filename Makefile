# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 21:39:21 by llinares          #+#    #+#              #
#    Updated: 2025/01/05 15:37:24 by mbirou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AOE_temu

CC = gcc -g

SOURCES = $(shell find src -name '*.c')

LIB = lib/raylib/src/libraylib.a

OBJECTS = $(SOURCES:.c=.o)

INCLUDES = include

all: $(NAME)

raylib:
	@if ls lib | grep -q "raylib"; then \
		clear; \
		echo "\033[32;47;1m** raylib already exist **\033[1;m"; \
	else \
		git submodule init; \
		git submodule update; \
		cd lib/raylib/src/; \
		make PLATFORM=PLATFORM_DESKTOP; \
	fi


$(NAME): raylib $(OBJECTS)
	$(CC) $(OBJECTS) $(LIB) -o $(NAME) -lm -I$(INCLUDES) -g

%.o: %.c
	$(CC) -c $< -o $@ -I$(INCLUDES) -g

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

libclean:
	rm -rf lib/raylib

re: fclean all

.PHONY: all clean fclean re
