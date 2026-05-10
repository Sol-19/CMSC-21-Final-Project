#ifndef KNIGHT_H
#define KNIGHT_H
#include "../chess_struct.h"

int isLegalKnight(Move move);
int isCheckKnight(Piece board[8][8], int king_x, int king_y, Color turn);

#endif