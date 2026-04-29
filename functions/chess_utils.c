#include <stdio.h>
#include "chess_struct.h"
#include "chess_utils.h"


void printBoard(Piece board[8][8])
{
    for (int x = 0; x < 8; x++){
        for (int y = 0; y < 8; y ++){
            printPiece(board[x][y].type, board[x][y].color);
        }
    }
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
