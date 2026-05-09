#ifndef PAWN_H
#define PAWN_H
#include "../chess_struct.h"

int isLegalPawn (Piece board[8][8], Move move);
int isCheckPawn(Piece board[8][8], int king_x, int king_y, Color turn);


#endif