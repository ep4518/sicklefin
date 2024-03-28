#include "stdio.h"
#include "stdlib.h"
#include "defs.h"

#define FEN1 "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"
#define FEN2 "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2"
#define FEN3 "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2"
#define FEN4 "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1"
#define FEN2Q "8/3q1p2/8/5P2/4Q3/8/8/8 w - - 0 2"

void ShowSqAttBySide(const int side, const S_BOARD *pos) {

    int rank = 0;
    int file = 0;
    int sq = 0;

    printf("\n\nSquares attacked by:%c\n", SideChar[side]);
    for (rank = RANK_8; rank >= RANK_1; --rank) {
        for (file = FILE_A; file <= FILE_H; ++file) {
            sq = FR2SQ(file, rank);
            if (SqAttacked(sq, side, pos) == TRUE) {
                printf("X");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    AllInit();

    S_BOARD board[1];

    ParseFen(FEN2Q, board);

    PrintBoard(board);
    printf("\n\nWhite Attacking: \n");
    ShowSqAttBySide(WHITE, board);

    printf("\n\nBlack Attacking: \n");
    ShowSqAttBySide(BLACK, board);
    // ASSERT(CheckBoard(board));
    // printf("\nwP:\n");
    // PrintBitBoard(board->pawns[WHITE]);
    // printf("\nbP:\n");
    // PrintBitBoard(board->pawns[BLACK]); 
    // printf("\nall P:\n");
    // PrintBitBoard(board->pawns[BOTH]);

    // ParseFen(START_FEN, board);
    // PrintBoard(board);
    // ParseFen(FEN1, board);
    // PrintBoard(board);
    // ParseFen(FEN2, board);
    // PrintBoard(board);
    // ParseFen(FEN3, board);
    // PrintBoard(board);

    // U64 playBitBoard = 0ULL;

    // playBitBoard |= (1ULL << SQ64(D2));
    // playBitBoard |= (1ULL << SQ64(D3));
    // playBitBoard |= (1ULL << SQ64(D4));

    // int sq64 = 0;
    // while (playBitBoard) {
    //     sq64 = POP(&playBitBoard);
    //     printf("Popped: %d", sq64);
    //     PrintBitBoard(playBitBoard);
    // }
    // // U64 playBitBoard = 0ULL;

    // printf("Start:\n\n");
    // PrintBitBoard(playBitBoard);

    // playBitBoard |= (1ULL << SQ64(D2));
    // printf("D2 Added:\n\n");
    // PrintBitBoard(playBitBoard);

    // playBitBoard |= (1ULL << SQ64(G2));
    // printf("G2 Added:\n\n");
    // PrintBitBoard(playBitBoard);

    // for (int index = 0; index < BRD_SQ_NUM; ++index) {
    //     if (index%10 == 0) printf("\n");
    //     printf("%5d", Sq120ToSq64[index]);
    // }

    // printf("\n\n");

    // for (int index = 0; index < 64; ++index) {
    //     if (index % 8 == 0) printf("\n");
    //     printf("%5d", Sq64ToSq120[index]);
    // }

    // printf("\n\n");

    return 0;
}