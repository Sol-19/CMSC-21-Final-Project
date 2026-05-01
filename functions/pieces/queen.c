#include "../chess_struct.h"
#include "../chess_utils.h"
#include "bishop.h"
#include "rook.h"
#include <stdlib.h>
#include <stdio.h>

int isLegalQueen(Move move, Piece board[8][8])
{
    int row_diff = abs(move.to_x - move.from_x);
    int col_diff = abs(move.to_y - move.from_y);

    int is_diagonal = (row_diff == col_diff);
    int is_straight = (row_diff == 0 || col_diff == 0);

    if (is_diagonal) return isLegalBishop(move, board);
    if (is_straight) return isLegalRook(move, board);
    
    return 0;

}