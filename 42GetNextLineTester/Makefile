# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 21:36:53 by msariasl          #+#    #+#              #
#    Updated: 2022/12/01 16:17:51 by msariasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDO = $(shell find ../. -name "*.c" ! -name "*bonus.c"  ! -name "bonus.c")
BONUS = $(shell find ../. -name "*bonus.c" ! -name "mando.c")

test:
	make mando
	make bonus

mando:
	@clear
	@gcc $(MANDO)
	@./a.out

bonus:
	@clear
	@gcc $(BONUS)
	@./a.out
	
clean:
	@rm -rf a.out
	@clear
