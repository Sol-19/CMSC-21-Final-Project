#include "../chess_struct.h"
#include "../chess_utils.h"
#include <stdio.h>

int isLegalBishop(Move move, Piece board[8][8])
{
    int row_diff = abs(move.to_x - move.from_x);
    int col_diff = abs(move.to_y - move.from_y);

    // must be diagonal
    if (row_diff != col_diff) return 0;

    int row_direction = (move.to_x > move.from_x) ? 1 : -1;
    int col_direction = (move.to_y > move.from_y) ? 1 : -1;

    // starting row and col to check
    int row = move.from_x + row_direction;
    int col = move.from_y + col_direction;

    //check if path is cleaer
    while (row != move.to_x && col != move.to_y) {
        if (board[row][col].type != EMPTY) return 0;
        row += row_direction;
        col += col_direction;
    }

    return 1;

}