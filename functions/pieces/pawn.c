#include "../chess_struct.h"
#include "../chess_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int enPassant(Piece board[8][8], Move move, Color turn) {
    
    Piece piece = board[move.from_x][move.from_y];
    Piece destination = board[move.to_x][move.to_y];
    Piece adjacent_piece = board[move.from_x][move.to_y]; //the piece next to / the same row as the piece, but col is in the place of atk

    int col_diff = abs(move.to_y - move.from_y);

    if (piece.type != PAWN) {
        return 0;
    }

    int step = (piece.color == WHITE) ? -1 : 1; //white[6][] moves up, black[1][] moves down

    if (col_diff == 1 && move.to_x == move.from_x + step) { //if pawn moves diagonally / attacks
        if (destination.type == EMPTY) { //place of atk is empty
            if (adjacent_piece.type == PAWN && adjacent_piece.color != piece.color && adjacent_piece.move_count == 1 && (piece.color == WHITE ? move.from_x == 3 : move.from_x == 4)) {
                printf("enpassant triggered on islegal");
                move.type = ENPASSANT;
                return 1; 
                // checks if enemy piece next to pawn is also a pawn and has only moved once (the ternary operator checks if the pawn is in the correct row, meaning the enemy pawn moved 2 steps in their 1st move)
            }
        }
    }
    return 0;
}

int isLegalPawn (Piece board[8][8], Move move, Color turn) {//refactor to use the move struct
    
    int col_diff = abs(move.to_y - move.from_y);

    Piece piece = board[move.from_x][move.from_y];
    Piece destination = board[move.to_x][move.to_y];
    
    

    if (piece.type != PAWN) {
        return 0; //returns false if not pawn
    }

    int step = (turn == WHITE) ? -1 : 1; //white[6][] moves up, black[1][] moves down

    if (col_diff == 0) { //if pawn is on the same col
        if (move.to_x == move.from_x + step) { //if pawn moves one step forward
            if (destination.type == EMPTY) {
                return 1; //if the destination is empty, return true
            }   
        }
        if ((turn == WHITE && move.from_x == 6) || (turn == BLACK && move.from_x == 1)) { //if pawn is not moved yet
            if (move.to_x == move.from_x + step * 2) { //if user wants to move 2 steps
                if (destination.type == EMPTY && board[move.from_x + step][move.from_y].type == EMPTY) {
                    return 1; //if the next 2 rows are empty, returns true
                }
            }
        }
    }
    else if (col_diff == 1 && move.to_x == move.from_x + step) { //if pawn attacks
        if (destination.type != EMPTY && destination.color != piece.color) {
            return 1; //if destination is not empty and the opposite color, return true
        }
    }
    return enPassant(board, move, turn);
}

int isCheckPawn(Piece board[8][8], int king_x, int king_y, Color turn)
{
    int pawn_dir = (turn == WHITE) ? -1 : 1;
    int pawn_attacks[2][2] = {
        {pawn_dir, -1},{pawn_dir, 1}
    };
    int row_check_pos = 0;
    int col_check_pos = 0;

    for (int i = 0; i < 2; i++){
        row_check_pos = king_y + pawn_attacks[i][0];
        col_check_pos = king_x + pawn_attacks[i][1];
        if (row_check_pos >= 0 && row_check_pos < 8 && col_check_pos >= 0 && col_check_pos < 8){
            if (board[row_check_pos][col_check_pos].type == PAWN && board[row_check_pos][col_check_pos].color != turn){
                return 1;
            }
        }
    }
    return 0;

}


int pawnPromotion(Piece board[8][8],Move move, Color turn)
{
    Piece piece = board[move.to_x][move.to_y];// this means that the pawn is already at the designation
    if(piece.type != PAWN) // this checks if its a pawn
    {
        return 0;
    }
    int promotion_row = (turn == WHITE)? 0:7; 
    if (move.to_x == promotion_row)
    {
        char choice;
        PieceType chosen_type;
        printf("You have achieved pawn promotion choose piece [queen=Q, rook=R, bishop=B, rook=r]");
        while(1)
        {
            scanf("%c", &choice);
            choice = toupper(choice);
            if (choice == 'Q'){chosen_type = QUEEN; break;}
            else if (choice == 'R'){chosen_type = ROOK; break;}
            else if (choice == 'B'){chosen_type = BISHOP; break;}
            else printf("Inavalid input try again dumb bitch");
        }
        board[move.to_x][move.to_y].type = chosen_type;
        return 1;
    }
    return 0;
}