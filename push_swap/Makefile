# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 17:01:17 by mrolfe            #+#    #+#              #
#    Updated: 2019/05/26 20:02:22 by mrolfe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/check.c srcs/filling_struct.c srcs/functions.c srcs/functions2.c 
		srcs/functions3.c srcs/push_swap.c srcs/sorting.c
OBJ = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ./libft/libft.a
INC = -I ./includes
LIBLINK = -L ./libft -lft
LIBINC = -I ./libft/includes

all: $(NAME) 

%.o:%.c
	@$(CC) $(CFLAGS) $(LIBINC) $(INC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft
	@echo "OK!"

$(NAME): libft $(OBJ)
	@echo "Compiling push_swap..."
	@$(CC) $(LIBLINK) -o $(NAME) $(OBJ)
	@echo "OK!"

rmlib:
	@echo "Deleting libft object files and libft.a..."
	@make fclean -C ./libft
	@echo "OK!"

clean: rmlib
	@echo "Deleting fillit object files..."
	@rm -rf $(OBJ)
	@echo "OK!"

fclean: clean
	@echo "Deleting fillit..."
	@rm -rf $(NAME)
	@echo "OK!"

re: fclean all