#ifndef BISHOP_H
#define BISHOP_H
#include "../chess_struct.h"

int isLegalBishop(Move move, Piece board[8][8]);
int isCheckBishop(Piece board[8][8], int king_x, int king_y, Color turn);

#endif