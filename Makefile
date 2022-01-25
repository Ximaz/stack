MODULES=stack/stack.c
EXEC=main
CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic

all: $(EXEC)

$(EXEC).o: $(EXEC).c
	$(CC) -c $(EXEC).c $(CFLAGS)

$(EXEC): $(EXEC).o
	$(CC) -o $(EXEC) $(EXEC).o $(MODULES) $(CFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(EXEC)

re: fclean all

run: re clean
	./$(EXEC)

.PHONY: all clean fclean re
