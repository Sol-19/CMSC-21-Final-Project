#ifndef KING_H
#define KING_H
#include "../chess_struct.h"

int isLegalKing(Piece board[8][8], Move move, Color turn);
int squareAttacked(int row, int col, Piece board[8][8], Color turn);

#endif