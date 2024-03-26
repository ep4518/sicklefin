#include "stdio.h"
#include "defs.h"

int main() {

    AllInit();

    U64 playBitBoard = 0ULL;

    printf("Start:\n\n");
    PrintBitBoard(playBitBoard);

    playBitBoard |= (1ULL << SQ64(D2));
    printf("D2 Added:\n\n");
    PrintBitBoard(playBitBoard);

    playBitBoard |= (1ULL << SQ64(G2));
    printf("G2 Added:\n\n");
    PrintBitBoard(playBitBoard);

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