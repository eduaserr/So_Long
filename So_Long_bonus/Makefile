# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 16:02:10 by eduaserr          #+#    #+#              #
#    Updated: 2025/10/26 02:15:06 by eduaserr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
NAME	:= So_Long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -O3 -g
LIBMLX	:= ./lib/MLX42
LIB		:= ./lib/libft
CC		:= clang

HEADERS	:= -I ./inc -I $(LIBMLX)/include/MLX42
LIBS	:= -L $(LIB) -lft -L $(LIBMLX)/build/ -lmlx42 -ldl -lglfw -pthread -lm

### SRC ###
SRC		:= ./main.c
SRCS	:= src/init/check_elements.c src/init/check_path.c\
		src/enemy/path.c\
		src/parse/parse_input.c src/parse/get_map.c\
		src/mlx/mlx_init.c src/mlx/mlx_keyhook.c\
		src/utils/utils_map.c src/utils/utils_free.c src/utils/utils_free2.c\
		src/utils/utils_mlx.c src/utils/utils_mlx2.c src/utils/utils_parse.c

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


$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	echo "Game compiled"

clean:
	$(MAKE) -C $(LIB) clean
	rm -rf $(OBJS)
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIB) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx