#include "functions/chess_utils.h"
#include "functions/chess_struct.h"
#include "functions/chess_set_board.h"
#include <stdio.h>
#include <string.h>

int main()
{
    Piece board[8][8] = {0};
    Piece previousBoard[8][8];
    Move playermoveturn;
    setBoard(board);
    gameLoop(board, previousBoard);
  
    printf("\n");

    return 0;
}


