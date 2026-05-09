#include "king.h"
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
                && !(squareAttacked(row, 5, board, turn))
                && !(squareAttacked(row, 6, board, turn))
            );
            case CASTLE_QUEENSIDE:
                return (
                !(board[row][4].move_count) //if king is not moved
                && (board[row][0].type == ROOK && board[row][0].color==turn && !(board[row][0].move_count))//and its a same color rook and not moved
                && (board[row][3].type==EMPTY) // and three squares empty
                && (board[row][2].type==EMPTY) 
                && (board[row][1].type==EMPTY) 
                && !(squareAttacked(row, 3, board, turn))
                && !(squareAttacked(row, 2, board, turn))
                && !(squareAttacked(row, 1, board, turn))
                );
    }
}

int squareAttacked(int row, int col, Piece board[8][8], Color turn){
    int king_x;
    int king_y;
    Piece simulated_board[8][8] = {0};
    currentBoard(board, simulated_board);//copies the board with a simulated board 
    findKing(simulated_board, turn, &king_x, &king_y); //finds the king 
    simulated_board[king_y][king_x].type = EMPTY; // changes the kings position into empty;
    simulated_board[row][col].type = KING; //simulates the king to be in the designated positions
    simulated_board[row][col].color = turn;
    if (isCheck(simulated_board, turn)){ //checks for check in the simulated board
        return 1;
    }
    return 0;
}