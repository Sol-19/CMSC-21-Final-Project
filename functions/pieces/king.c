#include "../chess_struct.h"
#include "../chess_utils.h"
#include <stdio.h>

int isLegalKing(Piece board[8][8], Move move, Color turn)
{
    switch(turn){
        case WHITE:
            switch(move.type){
                case NORMAL:
                    int row_diff = abs(move.to_x - move.from_x);
                    int col_diff = abs(move.to_y - move.from_y);
                    // add the logic for if king is incheck here :>
                    return (row_diff <= 1 && col_diff <= 1);
                case CASTLE_KINGSIDE:
                    return( 
                    !(board[7][4].move_count) //if king is not moved
                    && (board[7][7].type == ROOK && board[7][7].color==WHITE)//and its a white rook
                    && !(board[7][7].move_count) // and not moved
                    && (board[7][6].type==EMPTY) // and two squares empty
                    && (board[7][5].type==EMPTY) 
                    //add more if not checked when going to the destination
                );
                case CASTLE_QUEENSIDE:
                    return 1;
        }
        case BLACK:
            switch(move.type){
                case NORMAL:
                    int row_diff = abs(move.to_x - move.from_x);
                    int col_diff = abs(move.to_y - move.from_y);
                    // add the logic for if king is incheck here :>
                    return (row_diff <= 1 && col_diff <= 1);
                case CASTLE_KINGSIDE:
                    return 1;
                case CASTLE_QUEENSIDE:
                    return 1;
        }
    }
}