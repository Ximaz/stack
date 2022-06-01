CC=gcc
LIBFLAGS=-I./include -L./ -lstack
CFLAGS=-Wall -Wextra -Werror -Wno-deprecated -pedantic -O3
SECURE_CFLAGS=-fsanitize=address -fsanitize=undefined# -fsanitize=leak
SRC=src/stack.c
OBJ=*.o

NAME=stack
TEST=main.c
LIBNAME=libstack.a

$(NAME): $(LIBNAME)
	$(CC) $(CFLAGS) $(SECURE_CFLAGS) -o $(NAME) $(TEST) $(LIBFLAGS)

$(LIBNAME): $(OBJ)
	ar rc $(LIBNAME) obj/$(OBJ)

$(OBJ): $(SRC) obj/
	$(CC) $(CFLAGS) $(SECURE_CFLAGS) -c $(SRC)
	mv $(OBJ) obj/

obj/:
	mkdir -p obj

all: $(NAME)

clean:
	rm -rf obj/$(OBJ)

fclean:
	rm -rf $(LIBNAME) $(NAME)

re: fclean clean

.PHONY: all clean re
