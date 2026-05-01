#include "../chess_struct.h"
#include "../chess_utils.h"
#include <stdio.h>
#include <stdlib.h>

int isLegalKnight(Move move)
{
    int row_diff = abs(move.to_x - move.from_x);
    int col_diff = abs(move.to_y - move.from_y);

    return (row_diff == 2 && col_diff == 1) || (row_diff == 1 && col_diff == 2);
}