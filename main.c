#include "functions/chess_utils.h"
#include "functions/chess_struct.h"
#include <stdio.h>

int main()
{
    Piece board[8][8] = {0};
    board[0][0].type = 4;
    board[0][0].color = -1;
    board[0][1].type = 3;
    board[0][1].color = -1;
    printBoard(board);
    return 0;
}
