#include "stdio.h"
#include "stdlib.h"
#include "defs.h"

#define PAWNMOVESW "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1"
#define PAWNMOVESB "rnbqkbnr/p1p1p3/3p3p/1p1p4/2P1Pp2/8/PP1P1PpP/RNBQKB1R b - e3 0 1"
#define KNIGHTSKINGS "5k2/1n6/4n3/6N1/8/3N4/8/5K2 w - - 0 1"
#define ROOKS "6k1/8/5r2/8/1nR5/5N2/8/6K1 b - - 0 1"
#define QUEENS "6k1/8/4nq2/8/1nQ5/5N2/1N6/6K1 b - - 0 1"
#define BISHOPS "6k1/1b6/4n3/8/1n4B1/1B3N2/1N6/2b3K1 b - - 0 1" 
#define CASTLE "r3k2r/8/8/8/8/8/8/R3K2R b KQkq - 0 1"
#define CASTLE2 "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1"

int main() {

    AllInit();

    S_BOARD board[1];
    S_MOVELIST list[1];

    ParseFen(START_FEN, board);
    PerftTest(3, board);

    return 0;

    // AllInit();

    // S_BOARD board[1];
    // S_MOVELIST list[1];

    // ParseFen(START_FEN, board);
    // GenerateAllMoves(board,list);

    // int MoveNum = 0;
    // int move = 0;

    // PrintBoard(board);
    // getchar();

    // for (MoveNum = 0; MoveNum <= list->count; ++MoveNum) {
    //     move = list->moves[MoveNum].move;

    //     if (!MakeMove(board, move)) {
    //         continue;
    //     }

    //     printf("\nMADE:%s\n", PrMove(move));
    //     PrintBoard(board);

    //     TakeMove(board);
    //     printf("\nTAKEN:%s\n", PrMove(move));
    //     PrintBoard(board);

    //     getchar();
    // }
    // return 0;
}