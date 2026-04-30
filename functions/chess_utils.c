#include <stdio.h>
#include "chess_struct.h"
#include "chess_utils.h"
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
    char move_from[MAX_INPUT], move_to[MAX_INPUT];
    Move move;

    printf("\n%s's turn\n", turn == WHITE ? "White" : "Black");

    while (1)
    {
        printf("Move from (Choose a piece): ");
        scanf(" %s", move_from);
        while (getchar() != '\n'); // clears buffer


        // castling special case
        if (strcmp(move_from, "O-O-O") == 0 || strcmp(move_from, "O-O") == 0) {
            move.type = (strcmp(move_from, "O-O") == 0) ? CASTLE_KINGSIDE : CASTLE_QUEENSIDE;
            return move;
        }

        printf("To: ");
        scanf(" %s", move_to);
        while (getchar() != '\n');

        if (strlen(move_from) != 2 || strlen(move_to) != 2 ||
        move_from[0] < 'a' || move_from[0] > 'h' || move_from[1] < '1' || move_from[1] > '8' ||
        move_to[0] < 'a' || move_to[0] > 'h' || move_to[1] < '1' || move_to[1] > '8' ||
        (move_from[0] == move_to[0] && move_from[1] == move_to[1]))
        {
            printf("Invalid input, try again.\n");
            continue;
        }

        move.from_x = 8 - (move_from[1] - '0');
        move.from_y = move_from[0] - 'a';
        move.to_x   = 8 - (move_to[1] - '0');
        move.to_y   = move_to[0] - 'a';
        move.type = NORMAL;
        return move;


    }

}
