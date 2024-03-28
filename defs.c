#include "stdio.h"
#include "stdlib.h"
#include "defs.h"

#define FEN1 "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"
#define FEN2 "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2"
#define FEN3 "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2"
#define FEN4 "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1"
#define FEN2Q "8/3q1p2/8/5P2/4Q3/8/8/8 w - - 0 2"

void PrintBin(int move) {
    int i;
    printf("As binary: ");
    for (i = 27; i >= 0; i--) {
        if ((1<<i) & move) printf("1");
        else printf("0");
        if (i!=28 && i%4==0) printf(" ");
    }
    printf("\n");
}

int main() {

    AllInit();

    S_BOARD board[1];

    ParseFen(FEN4, board);
    PrintBoard(board);
    ASSERT(CheckBoard(board));

    int move = 0;
    int from = 6; int to = 12;
    int capt = wR; int prom = bR;

    move = ( from ) | ( to << 7 ) | (capt << 14 ) | (prom << 20);

    printf("\ndec:%d hex: %X\n", move, move);
    PrintBin(move);

    printf("from: %d to: %d capt: %d prom: %d\n", 
        FROMSQ(move), TOSQ(move), CAPTURED(move),
        PROMOTED(move));

    move |= MFLAGPS;

    printf("is PST: %s\n", (move & MFLAGPS) ? "YES" : "NO");


    return 0;
}