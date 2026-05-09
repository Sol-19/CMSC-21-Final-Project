#ifndef ROOK_H
#define ROOK_H
#include "../chess_struct.h"

int isLegalRook(Move move, Piece board[8][8]);
int isCheckRook(Piece board[8][8], int king_x, int king_y, Color turn);

#endif