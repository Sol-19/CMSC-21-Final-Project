#include "functions/chess_utils.h"
#include "functions/chess_struct.h"
#include <stdio.h>

int main()
{
    Piece board[8][8] = {0};
    board[0][0].type = ROOK;
    board[0][0].color = BLACK;
    board[0][1].type = KNIGHT;
    board[0][1].color = BLACK;
    printBoard(board);
    return 0;
}


