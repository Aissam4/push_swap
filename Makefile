# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 12:16:43 by abarchil          #+#    #+#              #
#    Updated: 2021/12/15 13:27:01 by abarchil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE = main.c error_handling.c src/ft_memcmp.c src/ft_putstr.c src/ft_strlen.c \
	parsing.c src/ft_atoi.c sorting.c src/ft_isdigit.c src/ft_memmove.c sorting_utils.c\
	instructions_a.c instructions_b.c stack_init.c simple_sort.c sort_big_numbers.c \
	simple_sort_utils.c
OBJ_FILE = $(SRC_FILE:.c=.o)

NAME = push_swap

CC = gcc

RED = \033[0;31m
CYAN = \033[0;36m
YELLOW = \033[0;33m

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)
	@echo " $(RED)\
		██████╗ ██╗   ██╗ ██████╗██╗  ██╗   ██████╗ ██╗       ██╗ █████╗ ██████╗ \n\
		██╔══██╗██║   ██║██╔════╝██║  ██║  ██╔════╝ ██║  ██╗  ██║██╔══██╗██╔══██╗\n\
		██████╔╝██║   ██║╚█████╗ ███████║  ╚█████╗  ╚██╗████╗██╔╝███████║██████╔╝\n\
		██╔═══╝ ██║   ██║ ╚═══██╗██╔══██║   ╚═══██╗  ████╔═████║ ██╔══██║██╔═══╝ \n\
		██║     ╚██████╔╝██████╔╝██║  ██║  ██████╔╝  ╚██╔╝ ╚██╔╝ ██║  ██║██║     \n\
		╚═╝      ╚═════╝ ╚═════╝ ╚═╝  ╚═╝  ╚═════╝    ╚═╝   ╚═╝  ╚═╝  ╚═╝╚═╝     \n"
%.o: %.c
	@echo "$(CYAN)----------- COMPILING $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILE)
	@$(CC) $(CFLAGS) $(OBJ_FILE) -o $(NAME)
	
clean :
	@echo "$(YELLOW)------------ REMOVING OBJECT FILES"
	@rm -rf $(OBJ_FILE)

fclean : clean
	@echo "$(YELLOW)------------ REMOVING PUSH SWAP"
	@rm -rf $(NAME)

re : fclean all

.PHONY : clean re fclean