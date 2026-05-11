#include "../chess_struct.h"
#include "../chess_utils.h"
#include <stdio.h>
#include <stdlib.h>

int isLegalKnight(Move move)
{
    int row_diff = abs(move.destination_row - move.piece_row);
    int col_diff = abs(move.destination_column - move.piece_column);

    return (row_diff == 2 && col_diff == 1) || (row_diff == 1 && col_diff == 2);
}

int isCheckKnight(Piece board[8][8], int king_x, int king_y, Color turn)
{
    int knight_moves[8][2] = {
    {-2,-1},{-2,1},{-1,-2},{-1,2},
    {1,-2},{1,2},{2,-1},{2,1}
        };

    int row_check_pos = 0;
    int col_check_pos = 0;

        for (int i = 0; i < 8; i++){
            row_check_pos = king_y + knight_moves[i][0];
            col_check_pos = king_x + knight_moves[i][1];
            if (row_check_pos >= 0 && row_check_pos < 8 && col_check_pos >= 0 && col_check_pos < 8){
                if (board[row_check_pos][col_check_pos].type == KNIGHT && board[row_check_pos][col_check_pos].color != turn){
                    return 1;
                }
            }
        }
    return 0;
}