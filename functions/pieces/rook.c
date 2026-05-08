#include "../chess_struct.h"
#include "../chess_utils.h"
#include <stdlib.h>
#include <stdio.h>

int isLegalRook(Move move, Piece board[8][8])
{
    int row_diff = abs(move.to_x - move.from_x);
    int col_diff = abs(move.to_y - move.from_y);

    int is_horizontal = (row_diff == 0);
    int is_vertical   = (col_diff == 0);

    int row_increasing  = (move.to_x > move.from_x);
    int col_increasing = (move.to_y > move.from_y);

    // not a straight line
    if (!is_horizontal && !is_vertical) return 0;

    int row_direction = is_vertical   ? (row_increasing  ? 1 : -1) : 0;
    int col_direction = is_horizontal ? (col_increasing ? 1 : -1) : 0;  

    //current col and row to check
    int row = move.from_x + row_direction;
    int col = move.from_y + col_direction;

    // check if there's a piece in the way
    while (row != move.to_x || col != move.to_y) {
    if (board[row][col].type != EMPTY) return 0;
    row += row_direction;
    col += col_direction;
    }
    

    return 1;
}