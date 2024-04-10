DEBUG_FLAGS = -fsanitize=address -fsanitize=undefined -g -fno-omit-frame-pointer -Wall -pedantic

all: clear_screen build clean

clear_screen:
	@clear

build:
	@echo "Building the project..."
	gcc defs.c init.c bitboards.c board.c hashkeys.c data.c attack.c io.c movegen.c validate.c makemove.c perft.c search.c misc.c pvtable.c evaluate.c uci.c -o engine

sane:
	@echo "Building the project sane..."
	gcc ${DEBUG_FLAGS} defs.c init.c bitboards.c board.c hashkeys.c data.c attack.c io.c movegen.c validate.c makemove.c perft.c search.c misc.c pvtable.c evaluate.c uci.c -o engine

gdb:
	@echo "Building the project sane..."
	gcc -g defs.c init.c bitboards.c board.c hashkeys.c data.c attack.c io.c movegen.c validate.c makemove.c perft.c search.c misc.c pvtable.c evaluate.c uci.c -o engine


clean:
	rm -f defs.o init.o bitboards.o board.o hashkeys.o data.o attack.o io.o movegen.o validate.o makemove.o perft.o search.o misc.o pvtable.o evaluate.o uci.o
