#ifndef CHESS_UTILS_H
#define CHESS_UTILS_H

#include "chess_struct.h" 

void printBoard(Piece board[8][8]);
void printPiece(PieceType type, Color color);
Move playerMove(Color turn);
int isLegal(Move move, Piece board[8][8], Color turn);
void applyMove(Move move, Piece board[8][8], Color turn);
void gameLoop(Piece board[8][8], Piece previousBoard[8][8]);
void revertBoard(Piece board[8][8], Piece previousBoard[8][8]);
void currentBoard(Piece board[8][8], Piece previousBoard[8][8]);

#endif

