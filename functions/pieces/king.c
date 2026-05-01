#include "../chess_struct.h"
#include "../chess_utils.h"
#include <stdio.h>

int isLegalKing(Move move)
{
    int row_diff = abs(move.to_x - move.from_x);
    int col_diff = abs(move.to_y - move.from_y);

    // add the logic for if king is incheck here :>

    return (row_diff <= 1 && col_diff <= 1);

}