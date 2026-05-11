#include "../chess_struct.h"
#include "../chess_utils.h"
#include <stdlib.h>
#include <stdio.h>

int isLegalBishop(Move move, Piece board[8][8])
{
    int row_diff = abs(move.destination_row - move.piece_row);
    int col_diff = abs(move.destination_column - move.piece_column);

    int row_increasing  = (move.destination_row > move.piece_row);
    int col_increasing = (move.destination_column > move.piece_column);

    // must be diagonal
    if (row_diff != col_diff) return 0;

    int row_direction = row_increasing ? 1 : -1;
    int col_direction = col_increasing ? 1 : -1;

    // starting row and col to check
    int row = move.piece_row + row_direction;
    int col = move.piece_column + col_direction;

    //check if path is cleaer
    while (row != move.destination_row && col != move.destination_column) {
        if (board[row][col].type != EMPTY) return 0;
        row += row_direction;
        col += col_direction;
    }
    
    return 1;

}

int isCheckBishop(Piece board[8][8], int king_x, int king_y, Color turn)
{
    int diagonals[4][2] = {
    {1,1},{1,-1},{-1,1},{-1,-1}
    };

    int row = 0;
    int col = 0;
    int row_check_pos = 0;
    int col_check_pos = 0;

        for (int d = 0; d < 4; d++){
            row = diagonals[d][0];
            col = diagonals[d][1];
            row_check_pos = king_y + row;
            col_check_pos = king_x + col;
            while(row_check_pos >= 0 && row_check_pos < 8 && col_check_pos >= 0 && col_check_pos < 8)
            {
                if (board[row_check_pos][col_check_pos].type != EMPTY){
                    if ((board[row_check_pos][col_check_pos].type == BISHOP || board[row_check_pos][col_check_pos].type == QUEEN) && board[row_check_pos][col_check_pos].color != turn){
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