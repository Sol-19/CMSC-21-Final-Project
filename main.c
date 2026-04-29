#include "functions/chess_utils.h"
#include "functions/chess_struct.h"
#include "functions/chess_set_board.h"
#include <stdio.h>

int main()
{
    int i, j;
    Piece board[8][8] = {0};
    setBoard(board);
    printBoard(board);
    return 0;
}


