MODULES=stack/stack.c
EXEC=main
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(EXEC)

$(EXEC).o: $(EXEC).c
	$(CC) -c $(EXEC).c

$(EXEC): $(EXEC).o
	$(CC) -o $(EXEC) $(EXEC).o $(MODULES) $(CFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(EXEC)

re: fclean all

run: re
	./$(EXEC)

.PHONY: all clean fclean re
