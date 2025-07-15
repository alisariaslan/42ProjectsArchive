# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 12:40:05 by msariasl          #+#    #+#              #
#    Updated: 2022/12/22 09:14:27 by msariasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
DEBUG = gcc main.c $(NAME) && ./a.out
DEBUG_B = gcc bonus.c $(NAME) && ./a.out
FILES = $(shell find ../. -name "*.c" ! -name "main.c" ! -name "bonus.c" && find ../. -name "*.h")
OBJ = $(FILES:.c=.o)
RM = rm -f
AR = ar -rc
FLAGS = -Wall -Wextra -Werror

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
		ar -rc $(NAME) $(OBJ)

fclean:
	clear
	@rm -rf ../*.o
	@rm -rf $(NAME)
	@rm -rf "a.out"
	@rm -rf *.txt
	@echo Temizlendi.

show:
	clear
	nm $(NAME)
	@echo Got all archive files.

mando:
	@echo Test is running now for mandotory part...
	@make
	$(DEBUG)

bonus:
	@echo Test is running now for bonus part...
	@make
	@$(DEBUG_B)
	
test:
	@make mando
	@make bonus

d:
	clear
	$(DEBUG)

b:
	clear
	$(DEBUG_B)
