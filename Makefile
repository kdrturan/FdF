# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abturan <abturan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 16:33:29 by abturan           #+#    #+#              #
#    Updated: 2024/11/25 16:33:30 by abturan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = #-Wall -Wextra -Werror
LIBFT = libs/libft/libft.a
GNL = libs/get_next_line/get_next_line.a
MINILIBX = libs/minilibx-linux/libmlx_Linux.a

SRCS =  srcs/*.c

all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(MINILIBX)
	$(CC) $(CFLAGS) $(SRCS) \
	-I./includes \
	\
	-I./libs/libft \
	-I./libs/get_next_line \
	-I./libs/minilibx-linux \
	\
	libs/libft/libft.a \
	libs/get_next_line/get_next_line.a \
	\
	-L./libs/minilibx-linux \
	-lmlx -lX11 -lXext -lm -o fdf

$(LIBFT):
	@make -sC libs/libft

$(GNL):
	@make -sC libs/get_next_line

$(MINILIBX):
	@git clone https://github.com/42Paris/minilibx-linux.git libs/minilibx-linux  
	@make -sC libs/minilibx-linux

clean:
	@make fclean -sC libs/libft
	@make fclean -sC libs/get_next_line


fclean: clean
	@rm -rf $(NAME) libs/minilibx-linux

re: fclean all

.PHONY: all clean fclean re

update_libs:
	@git submodule update --init --recursive --remote

git_push: update_libs
	@git add .
	@read -p "Enter commit message: " message; \
    git commit -m "$$message"
	@git push