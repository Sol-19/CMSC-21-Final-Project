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
    board[0][2].type = BISHOP;
    board[0][2].color = BLACK;
    board[0][3].type = QUEEN;
    board[0][3].color = BLACK;
    board[0][4].type = KING;
    board[0][4].color = BLACK;
    board[0][5].type = BISHOP;
    board[0][5].color = BLACK;
    board[0][6].type = KNIGHT;
    board[0][6].color = BLACK;
    board[0][7].type = ROOK;
    board[0][7].color = BLACK;
    printBoard(board);
    return 0;
}
