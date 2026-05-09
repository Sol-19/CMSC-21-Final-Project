#include "../chess_struct.h"
#include "../chess_utils.h"
#include <stdio.h>
#include <stdlib.h>

int isLegalKing(Piece board[8][8], Move move, Color turn)
{
    int row = turn == WHITE?7:0;
        switch(move.type){
            case NORMAL:
                int row_diff = abs(move.to_x - move.from_x);
                int col_diff = abs(move.to_y - move.from_y);
                return (row_diff <= 1 && col_diff <= 1);
            case CASTLE_KINGSIDE:
                return( 
                !(board[row][4].move_count) //if king is not moved
                && (board[row][7].type == ROOK && board[row][7].color==turn && !(board[row][7].move_count))//and its a same color rook and not moved
                && (board[row][6].type==EMPTY) // and two squares empty
                && (board[row][5].type==EMPTY) 
                //add more if not checked when going to the destination
            );
            case CASTLE_QUEENSIDE:
                return (
                !(board[row][4].move_count) //if king is not moved
                && (board[row][0].type == ROOK && board[row][0].color==turn && !(board[row][0].move_count))//and its a same color rook and not moved
                && (board[row][3].type==EMPTY) // and three squares empty
                && (board[row][2].type==EMPTY) 
                && (board[row][1].type==EMPTY) 
                //add more if not checked when going to the destination
                );
    }
}