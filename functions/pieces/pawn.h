#ifndef PAWN_H
#define PAWN_H
#include "../chess_struct.h"

int enPassant(Piece board[8][8], Move move, Color turn);
int isLegalPawn (Piece board[8][8], Move move, Color turn);
int isCheckPawn(Piece board[8][8], int king_x, int king_y, Color turn);
int pawnPromotion(Piece board[8][8],Move move, Color turn);



#endif