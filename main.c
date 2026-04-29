#include "functions/chess_utils.h"
#include "functions/chess_struct.h"
#include <stdio.h>

int main()
{
    Piece board[8][8] = {0};
    board[0][0].type = 4;
    printf("board[0][0].type = %d\n", board[0][0].type);
    printBoard(board);
    return 0;
}
