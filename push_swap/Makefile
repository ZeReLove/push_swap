# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 17:01:17 by mrolfe            #+#    #+#              #
#    Updated: 2019/06/06 13:20:56 by mrolfe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/push_swap/check.c srcs/push_swap/filling_struct.c srcs/push_swap/functions.c srcs/push_swap/functions2.c \
		srcs/push_swap/functions3.c srcs/push_swap/push_swap.c srcs/push_swap/sorting.c srcs/push_swap/mediana_functions_for_a.c \
		srcs/push_swap/mediana_functions_for_b.c
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
	@echo "Deleting push_swap object files..."
	@rm -rf $(OBJ)
	@echo "OK!"

fclean: clean
	@echo "Deleting push_swap..."
	@rm -rf $(NAME)
	@echo "OK!"

re: fclean all