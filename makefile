all:
	gcc defs.c init.c bitboards.c board.c hashkeys.c data.c attack.c io.c movegen.c validate.c -o engine