#include "../chess_struct.h"
#include "../chess_utils.h"
#include <stdio.h>
#include <stdlib.h>

int isLegalPawn (Piece board[8][8], int start_row, int start_col, int end_row, int end_col) {
    Piece piece = board[start_row][start_col];
    Piece destination = board[end_row][end_col];

    if (piece.type != PAWN) {
        return 0; //returns false if not pawn
    }

    int move = (piece.color == WHITE) ? -1 : 1; //white[6][] moves up, black[1][] moves down

    if (start_col == end_col) { //if pawn is on the same col
        if (start_row + move == end_row) { //if pawn moves one step forward
            if (destination.type == EMPTY) {
                return 1; //if the destination is empty, return true
            }   
        }
        if ((piece.color == WHITE && start_row == 6) || (piece.color == BLACK && start_row == 1)) { //if pawn is not moved yet
            if (start_row + 2*move == end_row) { //if user wants to move 2 steps
                if (destination.type == EMPTY && board[start_row + move][start_col].type == EMPTY) {
                    return 1; //if the next 2 rows are empty, returns true
                }
            }
        }
    }
    else if (abs(start_col - end_col) == 1 && (start_row + move == end_row)) { //if pawn attacks
        if (destination.type != EMPTY && destination.color != piece.color) {
            return 1; //if destination is not empty and the opposite color, return true
        }
    }
}
