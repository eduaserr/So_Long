# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 16:02:10 by eduaserr          #+#    #+#              #
#    Updated: 2024/12/11 15:43:32 by eduaserr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
NAME	:= Game
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42
LIB		:= ./lib/libft

HEADERS	:= -I ./inc -I $(LIBMLX)/include/MLX42
LIBS	:= -L $(LIB) -lft -L $(LIBMLX)/build/ -lmlx42 -ldl -lglfw -pthread -lm

### SRC ###
SRC		:= ./main.c
SRCS	:= src/parse/parse_input.c

### OBJ ###
OBJS	:= ${SRCS:.c=.o} $(SRC:.c=.o)

### RULES ###
all: libmlx $(NAME)

libmlx:
	$(MAKE) -C $(LIB)
	cmake $(LIBMLX) -B $(LIBMLX)/build
	make -C $(LIBMLX)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	echo "Game compiled"

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	$(MAKE) -C $(LIB) clean
	rm -rf $(OBJS)
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIB) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx