#include "functions/chess_utils.h"
#include "functions/chess_struct.h"
#include <stdio.h>

int main()
{
    Piece board[8][8];
    board[0][0].type = ROOK;
    printBoard();
    return 0;
}
