#ifndef DEFS_H
#define DEFS_H

#include "stdlib.h"

/* Define ASSERT */
// define DEBUG for debugging
#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)) { \
printf("%s - Failed ", #n); \
printf("On %s ",__DATE__); \
printf("At %s ",__TIME__); \
printf("In File %s ",__FILE__); \
printf("At Line %d\n",__LINE__); \
exit(1);}
#endif

typedef unsigned long long U64;

#define NAME "Vice 1.0"
#define BRD_SQ_NUM 120

#define MAXGAMEMOVES 2048  // half moves

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bB, bR, bQ, bK };

enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };
enum { WHITE, BLACK, BOTH };
enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum { FALSE, TRUE };

// White/ Black, King/ Queen, Castling.
//      0 0 0 0 => castling permutations
// can only castle once for each option
enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8 };

// contains info to undo a move
typedef struct {

    int move;
    int castlePerm;
    int enp;
    int fifty;
    U64 posKey;

} S_UNDO;

// Defining board structure
typedef struct {

    int pieces[BRD_SQ_NUM];
    // 3 because 1, 2, 3 represent WHITE, BLACK, BOTH
    U64 pawns[3]; // 01000000 where the 64 bit number represents all board locations of rank 1 e.g. A1 -> H1 to rank 8
    
    int KingSq[2];

    int side; // side to move
    int enPas;  // Optional en passant square
    int fiftyMove; // fifty move counter

    int ply; // how many half moves
    int hisply; // total number of half moves

    int castlePerm; // perm from enum above 0 - 7

    U64 posKey; // unique key for each posistion

    int pceNum[13];     // peices on the board, index from enum above
    int bigPce[3];      // anything that isn't a pawn
    int majPce[3];      // number of rooks and queens
    int minCe[3];       // number of bishops and knights
                        // each have 3 for black, white and both
    S_UNDO history[MAXGAMEMOVES];   // everytime a move is made, before executed, move is stored in history
                                    // move info is move, castlePerms, enPas, fiftyMove and uniqueKey before move
    // piece list
    int pList[13][10];

    // pList[wN][0] = E1; pList[wN][1] = D4; ...
    // Can now iterate through piece list for move generation

} S_BOARD;

/* MACROS */

// converts file and rank to equiv 120 array based number
#define FR2SQ(f,r) ( (21 + (f) ) + ( (r) * 10 ))
#define SQ64(sq120) Sq120ToSq64[sq120]

/* GLOBALS */

extern int Sq120ToSq64[BRD_SQ_NUM];
extern int Sq64ToSq120[64];

/* FUNCTIONS */

// init.c
extern void AllInit();

//  bitboards.c
extern void PrintBitBoard(U64 bb);

#endif

// for generating all the moves for a player, rather than iterate the board, find peices and then generate moves
// It is more efficient to hold a piece list