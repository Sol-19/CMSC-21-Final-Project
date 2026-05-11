#include "../chess_struct.h"
#include "../chess_utils.h"
#include <stdlib.h>
#include <stdio.h>

int isLegalRook(Move move, Piece board[8][8])
{
    int row_diff = abs(move.to_x - move.piece_row);
    int col_diff = abs(move.to_y - move.piece_column);

    int is_horizontal = (row_diff == 0);
    int is_vertical   = (col_diff == 0);

    int row_increasing  = (move.to_x > move.piece_row);
    int col_increasing = (move.to_y > move.piece_column);

    // not a straight line
    if (!is_horizontal && !is_vertical) return 0;

    int row_direction = is_vertical   ? (row_increasing  ? 1 : -1) : 0;
    int col_direction = is_horizontal ? (col_increasing ? 1 : -1) : 0;  

    //current col and row to check
    int row = move.piece_row + row_direction;
    int col = move.piece_column + col_direction;

    // check if there's a piece in the way
    while (row != move.to_x || col != move.to_y) {
    if (board[row][col].type != EMPTY) return 0;
    row += row_direction;
    col += col_direction;
    }
    

    return 1;
}

int isCheckRook(Piece board[8][8], int king_x, int king_y, Color turn)
{
    int directions[4][2] =  {
        {1,0},{-1,0},{0,1},{0,-1}//y increment index 0 & 1, x increment for index 2 & 3
    };
    int row = 0;
    int col = 0;
    int row_check_pos = 0;
    int col_check_pos = 0;

    for (int d = 0; d < 4; d++){
        row = directions[d][0]; // get row directions(+-1)
        col = directions[d][1]; // get col directions(+-1)
        row_check_pos = king_y + row;
        col_check_pos = king_x + col;
        while(row_check_pos >= 0 && row_check_pos < 8 && col_check_pos >= 0  && col_check_pos < 8) //check for bounds 
        {
            if (board[row_check_pos][col_check_pos].type != EMPTY){
                if ((board[row_check_pos][col_check_pos].type == ROOK || board[row_check_pos][col_check_pos].type == QUEEN ) && (board[row_check_pos][col_check_pos].color != turn)){
                return 1;
            }
            break;
        }
        row_check_pos += row;
        col_check_pos += col;
        }
    }
    return 0;
}