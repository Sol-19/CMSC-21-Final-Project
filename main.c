#include "functions/chess_utils.h"
#include "functions/chess_struct.h"
#include "functions/chess_set_board.h"
#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    char move_from[100];
    char move_to[100];
    Piece board[8][8] = {0};
    Move playermoveturn;
    setBoard(board);
    printBoard(board);
    printf("\n");
    //we return true(1) in is legal, that means the move is legal
    do{
        while (1) {
            playermoveturn = playerMove(WHITE);
            if (isLegal(playermoveturn, board, WHITE)) break;
            printf("Illegal move, try again.\n");
        }
        applyMove(playermoveturn, board, WHITE);
        printBoard(board);
        while (1) {
            playermoveturn = playerMove(BLACK);
            if (isLegal(playermoveturn, board, BLACK)) break;
            printf("Illegal move, try again.\n");
        }
        applyMove(playermoveturn, board, BLACK);
        printBoard(board);
    }while(1);//change to checkmate later in inplementation
    return 0;
}


