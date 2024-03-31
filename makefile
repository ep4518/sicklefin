all: clear_screen build

clear_screen:
	@clear

build:
	@echo "Building the project..."
	gcc defs.c init.c bitboards.c board.c hashkeys.c data.c attack.c io.c movegen.c validate.c makemove.c perft.c -o engine