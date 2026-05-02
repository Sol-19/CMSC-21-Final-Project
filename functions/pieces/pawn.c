#include "../chess_struct.h"
#include "../chess_utils.h"
#include <stdio.h>
#include <stdlib.h>

int isLegalPawn (Piece board[8][8], Move move) {//refactor to use the move struct
    
    int col_diff = abs(move.to_y - move.from_y);

    Piece piece = board[move.from_x][move.from_y];
    Piece destination = board[move.to_x][move.to_y];

    if (piece.type != PAWN) {
        return 0; //returns false if not pawn
    }

    int step = (piece.color == WHITE) ? -1 : 1; //white[6][] moves up, black[1][] moves down

    if (col_diff == 0) { //if pawn is on the same col
        if (move.to_x == move.from_x + step) { //if pawn moves one step forward
            if (destination.type == EMPTY) {
                return 1; //if the destination is empty, return true
            }   
        }
        if ((piece.color == WHITE && move.from_x == 6) || (piece.color == BLACK && move.from_x == 1)) { //if pawn is not moved yet
            if (move.to_x == move.from_x + step * 2) { //if user wants to move 2 steps
                if (destination.type == EMPTY && board[move.from_x + step][move.from_y].type == EMPTY) {
                    return 1; //if the next 2 rows are empty, returns true
                }
            }
        }
    }
    else if (col_diff == 1 && move.to_x == move.from_x + step) { //if pawn attacks
        if (destination.type != EMPTY && destination.color != piece.color) {
            return 1; //if destination is not empty and the opposite color, return true
        }
    }
    return 0;
}

