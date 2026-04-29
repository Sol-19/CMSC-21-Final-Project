#include <stdio.h>
#include "chess_struct.h"
#include "chess_utils.h"
#define RED   "\033[31m"
#define BLUE  "\033[34m"
#define RESET "\033[0m"


void printBoard(Piece board[8][8])
{
    for (int x = 0; x < 8; x++){
        for (int y = 0; y < 8; y ++){
            printPiece(board[x][y].type, board[x][y].color);
        }
        printf("\n\n");
    }
}

void printPiece(PieceType type, Color color) {
    switch (color){
        case WHITE: printf(BLUE); break;
        case BLACK: printf(RED); break;
    }
    switch(type) {
        case EMPTY:  printf("*\t");  break;
        case PAWN:   printf("P\t");   break;
        case BISHOP: printf("B\t"); break;
        case KNIGHT: printf("N\t"); break;
        case ROOK:   printf("R\t");   break;
        case QUEEN:  printf("Q\t");  break;
        case KING:   printf("K\t");   break;
    }
    printf(RESET);
}
