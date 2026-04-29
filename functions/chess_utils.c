#include <stdio.h>
#include "chess_struct.h"
#include "chess_utils.h"


void printBoard(void)
{
    printf("Hi");
}

void printPiece(PieceType type, Color color) {
    switch(type) {
        case EMPTY:  printf("*");  break;
        case PAWN:   printf("P");   break;
        case BISHOP: printf("B"); break;
        case KNIGHT: printf("N"); break;
        case ROOK:   printf("R");   break;
        case QUEEN:  printf("Q");  break;
        case KING:   printf("K");   break;
    }
}
