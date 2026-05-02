#include <stdio.h>
#include "chess_struct.h"
#include "chess_utils.h"
#include "pieces/pawn.h"
#include "pieces/bishop.h"
#include "pieces/knight.h"
#include "pieces/rook.h"
#include "pieces/queen.h"
#include "pieces/king.h"
#include <string.h>
#define RED   "\033[31m"
#define BLUE  "\033[34m"
#define RESET "\033[0m"
#define MAX_INPUT 100


void printBoard(Piece board[8][8])
{
    int row, column;
    for (row = 0; row < 8; row++){
        printf("%d |\t", 8 - row);
        
        
        for (column = 0; column < 8; column ++){
            printPiece(board[row][column].type, board[row][column].color);
        }
        printf("\n\n");
    }

    printf("\t");
    for (row = 0; row < 8; row++)
    {
        printf("—\t");
    }
    printf("\n\t");

    for (int column = 0; column < 8; column++)
    {
        printf("%c\t", 'a' + column);
    }
}

void printPiece(PieceType type, Color color) {
    switch (color){
        case WHITE: printf(BLUE); break;
        case BLACK: printf(RED); break;
    }
    switch(type) {
        case EMPTY:  printf("*\t");  break;
        case PAWN:   printf("P\t");   break;
        case BISHOP: printf("B\t"); break;
        case KNIGHT: printf("N\t"); break;
        case ROOK:   printf("R\t");   break;
        case QUEEN:  printf("Q\t");  break;
        case KING:   printf("K\t");   break;
    }
    printf(RESET);
}

Move playerMove (Color turn)

{
    char piece_from[MAX_INPUT], piece_to[MAX_INPUT];
    Move move;

    printf("\n%s's turn\n", turn == WHITE ? "White" : "Black");

    while (1)
    {
        printf("Move from (Choose a piece): ");
        scanf(" %s", piece_from);
        while (getchar() != '\n'); // clears buffer


        // castling special case
        if ((strcmp(piece_from, "O-O-O") == 0) || (strcmp(piece_from, "O-O") == 0)) {
            move.type = (strcmp(piece_from, "O-O") == 0) ? CASTLE_KINGSIDE : CASTLE_QUEENSIDE;
            move.from_y = 4;
            move.from_x = turn == WHITE? 7 : 0;
            return move;
        }

        printf("To: ");
        scanf(" %s", piece_to);
        while (getchar() != '\n');

        if (strlen(piece_from) != 2 || strlen(piece_to) != 2 ||
        piece_from[0] < 'a' || piece_from[0] > 'h' || piece_from[1] < '1' || piece_from[1] > '8' ||
        piece_to[0] < 'a' || piece_to[0] > 'h' || piece_to[1] < '1' || piece_to[1] > '8' ||
        (piece_from[0] == piece_to[0] && piece_from[1] == piece_to[1]))
        {
            printf("Invalid input, try again.\n");
            continue;
        }

        move.from_x = 8 - (piece_from[1] - '0');
        move.from_y = piece_from[0] - 'a';
        move.to_x   = 8 - (piece_to[1] - '0');
        move.to_y   = piece_to[0] - 'a';
        move.type = NORMAL;
        return move;


    }

}

int isLegal(Move move, Piece board[8][8], Color turn)
{
    Piece piece_from = board[move.from_x][move.from_y];
    if (move.type == NORMAL){
    Piece piece_to = board[move.to_x][move.to_y];
    // can't capture ally piece
    if (piece_to.type != EMPTY && piece_to.color == turn) return 0;
    }
    // no piece or wrong color
    if (piece_from.type == EMPTY || piece_from.color != turn) return 0;

    //we return 1 for is legal<piece> that means the move is legal
    switch (piece_from.type) {
        case PAWN:  return isLegalPawn(board, move);
        case ROOK:   return isLegalRook(move, board);
        case KNIGHT: return isLegalKnight(move);
        case BISHOP: return isLegalBishop(move, board);
        case QUEEN:  return isLegalQueen(move, board);
        case KING:   return isLegalKing(board, move, turn);
        default: return 0;//checking if turns switch (all moves legal)
    }
}

void applyMove(Move move, Piece board[8][8], Color turn)
{
    if(move.type == NORMAL)
    {
        // move the piece by making the destination piece equal to the source piece and setting the source piece into EMPTY
        board[move.to_x][move.to_y] = board[move.from_x][move.from_y];
        board[move.to_x][move.to_y].move_count++;

        board[move.from_x][move.from_y].type = EMPTY;
        board[move.from_x][move.from_y].color = NONE;
    }
    else if(move.type == CASTLE_KINGSIDE)
    {
       int row = turn == WHITE?7:0;

        board[row][6] = board[row][4]; // switch king to col 6
        board[row][5]  = board[row][7]; // switch rook to col 5

        board[row][4].type = EMPTY; // set the original king to empty
        board[row][4].color = NONE;

        board[row][7].type = EMPTY; // set the original rook to empty
        board[row][7].color = NONE;

    }
    else if(move.type == CASTLE_QUEENSIDE)
    {
        int row = turn == WHITE?7:0;

        board[row][2] = board[row][4]; // switch king to col 2
        board[row][3]  = board[row][0]; // switch rook to col 3

        board[row][4].type = EMPTY; // set the original king to empty
        board[row][4].color = NONE;

        board[row][0].type = EMPTY; // set the original rook to empty
        board[row][0].color = NONE;
    }
}