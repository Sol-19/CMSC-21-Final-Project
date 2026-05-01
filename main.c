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
    do{
        do{
            playermoveturn = playerMove(WHITE);
        }while(!(isLegal(playermoveturn, board, WHITE)));
        do{
            playermoveturn = playerMove(WHITE);
        }while(!(isLegal(playermoveturn, board, BLACK)));
    }while(1);//change to checkmate later in inplementation



    

    return 0;
}


