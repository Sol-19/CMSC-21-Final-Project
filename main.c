#include "functions/chess_utils.h"
#include "functions/chess_struct.h"
#include <stdio.h>

int main()
{
    Piece board[8][8] = {0};
    board[0][0].type = ROOK; board[0][0].color = BLACK;
    board[0][1].type = KNIGHT; board[0][1].color = BLACK;
    board[0][2].type = BISHOP; board[0][2].color = BLACK;
    board[0][3].type = QUEEN; board[0][3].color = BLACK;
    board[0][4].type = KING; board[0][4].color = BLACK;
    board[0][5].type = BISHOP; board[0][5].color = BLACK;
    board[0][6].type = KNIGHT; board[0][6].color = BLACK;
    board[0][7].type = ROOK; board[0][7].color = BLACK;
    board[1][0].type = PAWN; board[1][0].color = BLACK;
    board[1][1].type = PAWN; board[1][1].color = BLACK;
    board[1][2].type = PAWN; board[1][2].color = BLACK;
    board[1][3].type = PAWN; board[1][3].color = BLACK;
    board[1][4].type = PAWN; board[1][4].color = BLACK;
    board[1][5].type = PAWN; board[1][5].color = BLACK;
    board[1][6].type = PAWN; board[1][6].color = BLACK;
    board[1][7].type = PAWN; board[1][7].color = BLACK;
    //board[2][0].type = EMPTY; board[2][0].color = NONE; (?)
    board[7][0].type = ROOK; board[7][0].color = WHITE;
    board[7][1].type = KNIGHT; board[7][1].color = WHITE;
    board[7][2].type = BISHOP; board[7][2].color = WHITE;
    board[7][3].type = QUEEN; board[7][3].color = WHITE;
    board[7][4].type = KING; board[7][4].color = WHITE;
    board[7][5].type = BISHOP; board[7][5].color = WHITE;
    board[7][6].type = KNIGHT; board[7][6].color = WHITE;
    board[7][7].type = ROOK; board[7][7].color = WHITE;
    board[6][0].type = PAWN; board[6][0].color = WHITE;
    board[6][1].type = PAWN; board[6][1].color = WHITE;
    board[6][2].type = PAWN; board[6][2].color = WHITE;
    board[6][3].type = PAWN; board[6][3].color = WHITE;
    board[6][4].type = PAWN; board[6][4].color = WHITE;
    board[6][5].type = PAWN; board[6][5].color = WHITE;
    board[6][6].type = PAWN; board[6][6].color = WHITE;
    board[6][7].type = PAWN; board[6][7].color = WHITE;
    printBoard(board);
    return 0;
}
