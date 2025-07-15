CLI_OUT = client
SW_OUT = server
CLI = $(CLI_OUT)*.c
SW = $(SW_OUT)*.c
HD = minitalk.h
ARGS = -Wall -Wextra -Werror
GCC = gcc $(ARGS)

$(CLI_OUT) : $(CLI) $(HD)
	$(GCC) $(CLI) $(HD) -c
	$(GCC) $(CLI_OUT).o -o $(CLI_OUT)

$(SW_OUT) : $(SW) $(HD)
	$(GCC) $(SW) $(HD) -c
	$(GCC) $(SW_OUT).o -o $(SW_OUT)

all:
	make $(CLI_OUT)
	make $(SW_OUT)

clean:
	rm -rf *.o
	rm -rf *.out
	rm -rf *.gch

fclean:
	make clean
	rm -rf $(CLI_OUT)
	rm -rf $(SW_OUT)

re:
	make fclean
	make all

n:
	clear
	norminette -R CheckForbiddenSourceHeader
