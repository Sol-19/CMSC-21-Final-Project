#include <stdio.h>
#include "chess_struct.h"
#include "chess_utils.h"
#include "pieces/pawn.h"
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
    char piece[MAX_INPUT], destination[MAX_INPUT];
    Move move;

    printf("\n%s's turn\n", turn == WHITE ? "White" : "Black");

    while (1)
    {
        printf("Move from (Choose a piece): ");
        scanf(" %s", piece);
        while (getchar() != '\n'); // clears buffer


        // castling special case
        if ((strcmp(piece, "O-O-O") == 0) || (strcmp(piece, "O-O") == 0)) {
            move.type = (strcmp(piece, "O-O") == 0) ? CASTLE_KINGSIDE : CASTLE_QUEENSIDE;

            // gets the coords of the king
            move.from_y = 4;
            move.from_x = turn == WHITE? 7 : 0;

            return move;
        }

        printf("To: ");
        scanf(" %s", destination);
        while (getchar() != '\n');

        if (strlen(piece) != 2 || strlen(destination) != 2 ||
        piece[0] < 'a' || piece[0] > 'h' || piece[1] < '1' || piece[1] > '8' ||
        destination[0] < 'a' || destination[0] > 'h' || destination[1] < '1' || destination[1] > '8' ||
        (piece[0] == destination[0] && piece[1] == destination[1]))
        {
            printf("Invalid input, try again.\n");
            continue;
        }

        move.from_x = 8 - (piece[1] - '0');
        move.from_y = piece[0] - 'a';
        move.to_x   = 8 - (destination[1] - '0');
        move.to_y   = destination[0] - 'a';
        move.type = NORMAL;
        return move;


    }

}

int isLegal(Move move, Piece board[8][8], Color turn)
{
    Piece piece = board[move.from_x][move.from_y];
    if (move.type == NORMAL){
    Piece destination = board[move.to_x][move.to_y];
    // can't capture ally piece
    if (destination.type != EMPTY && destination.color == turn) return 0;
    }
    // no piece or wrong color
    if (piece.type == EMPTY || piece.color != turn) return 0;

    //we return 1 for is legal<piece> that means the move is legal
    switch (piece.type) {
        // case PAWN:  return isLegalPawn(move, board, turn);
    //     case ROOK:   return isLegalRook(move, board);
    //     case KNIGHT: return isLegalKnight(move);
    //     case BISHOP: return isLegalBishop(move, board);
    //     case QUEEN:  return isLegalQueen(move, board);
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