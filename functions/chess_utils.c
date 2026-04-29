#include <stdio.h>
#include "chess_struct.h"
#include "chess_utils.h"


void printBoard(Piece board[8][8])
{
    for (int x = 0; x < 8; x++){
        for (int y = 0; y < 8; y ++){
            printPiece(board[x][y].type, board[x][y].color);
        }
        printf("\n");
    }
}

void printPiece(PieceType type, Color color) {
    switch(type) {
        case EMPTY:  printf("*\t");  break;
        case PAWN:   printf("P\t");   break;
        case BISHOP: printf("B\t"); break;
        case KNIGHT: printf("N\t"); break;
        case ROOK:   printf("R\t");   break;
        case QUEEN:  printf("Q\t");  break;
        case KING:   printf("K\t");   break;
    }
}
