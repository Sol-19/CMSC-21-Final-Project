#include <stdio.h>
#include "chess_struct.h"
#include "chess_utils.h"
#include "pieces/pawn.h"
#include "pieces/bishop.h"
#include "pieces/knight.h"
#include "pieces/rook.h"
#include "pieces/queen.h"
#include "pieces/king.h"
#include "pieces/knight.h"
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
    printf("\n");
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
        case PAWN:  return isLegalPawn(board, move);
        case ROOK:   return isLegalRook(move, board);
        case KNIGHT: return isLegalKnight(move);
        case BISHOP: return isLegalBishop(move, board);
        case QUEEN:  return isLegalQueen(move, board);
        case KING:   return isLegalKing(board, move, turn);
        default: return 0;//checking if turns switch (all moves legal)
    }
}

void currentBoard(Piece board[8][8], Piece previousBoard[8][8]){
    for (int x = 0; x<8; x++){
        for(int y = 0; y<8; y++){
            previousBoard[x][y] = board[x][y];
        }
    }
}

void revertBoard(Piece board[8][8], Piece previousBoard[8][8]){
    for (int x = 0; x<8; x++){
        for(int y = 0; y<8; y++){
            board[x][y] = previousBoard[x][y];
        }
    }
}

void applyMove(Move move, Piece board[8][8], Color turn) 
{
    if(move.type == NORMAL)
    {
   
        // move the piece by making the destination piece equal to the source piece and setting the source piece into EMPTY
        Piece *piece = &board[move.from_x][move.from_y]; 
        Piece *destination = &board[move.to_x][move.to_y];

        (*destination) = (*piece); // place the piece into its destination
        (*destination).move_count++; // increment since the piece has moved

        // set the original piece into nothing since it has already moved
        (*piece).type = EMPTY;
        (*piece).color = NONE;
        
    }
    else if(move.type == CASTLE_KINGSIDE)
    {
       int row = turn == WHITE?7:0;

        Piece *king = &board[row][4];
        Piece *rook = &board[row][7];
        Piece *king_dest = &board[row][6];
        Piece *rook_dest = &board[row][5];

        (*king_dest) = (*king); // switch king to col 6
        (*rook_dest) = (*rook); // switch rook to col 5

        (*king_dest).move_count++;
        (*rook_dest).move_count++;

        (*king).type = EMPTY; (*king).color = NONE; // set the original king to empty
        (*rook).type = EMPTY; (*rook).color = NONE; // set the original rook to empty

    }
    else if(move.type == CASTLE_QUEENSIDE)
    {
        int row = turn == WHITE?7:0;

        Piece *king = &board[row][4];
        Piece *rook = &board[row][0];

        Piece *king_dest = &board[row][2];
        Piece *rook_dest = &board[row][3];

        (*king_dest) = (*king); // switch king to col 2
        (*rook_dest) = (*rook); // switch rook to col 3

        (*king_dest).move_count++;
        (*rook_dest).move_count++;

        (*king).type = EMPTY; (*king).color = NONE; // set the original king to empty
        (*rook).type = EMPTY; (*rook).color = NONE; // set the original rook to empty

    }
}

void findKing(Piece board[8][8], Color turn, int *king_x, int *king_y){
    int kingfound = 0;
    for (int y = 0; y<8; y++){
        for (int x = 0; x<8; x++){
            if (board[y][x].type == KING && board[y][x].color == turn){
                *king_x = x;
                *king_y = y;
                kingfound = 1;
                break;
            }
        }
        if (kingfound){
            break;
        }
    }
}

int isCheck(Piece board[8][8], Color turn){

    int king_x, king_y;
    findKing(board, turn, &king_x, &king_y);

    return isCheckRook(board, king_x, king_y, turn)   || //checks both rook and queen
           isCheckBishop(board, king_x, king_y, turn) || // checks both bishop and queen
           isCheckKnight(board, king_x, king_y, turn) ||
           isCheckPawn(board, king_x, king_y, turn)   ||
           isCheckKing(board, king_x, king_y, turn);
}

int hasNoLegalMoves(Piece board[8][8], Color turn)
{
    Move move;
    Piece *piece = NULL;
    Piece previous_board[8][8];

    for(int row = 0; row < 8; row++)
    {
        for(int column = 0; column < 8; column++)
        {
           move.from_x = row;
           move.from_y = column;
           piece = &board[move.from_x][move.from_y];

           if( (*piece).type != EMPTY &&
               (*piece).color == turn)
            {
                for(int row2 = 0; row2 < 8; row2++)
                {
                    for(int column2 = 0; column2 < 8; column2++)
                    {

                        move.to_x = row2;
                        move.to_y = column2;
                        if(!isLegal(move,board,turn))
                        {
                            continue;
                        }

                         currentBoard(board, previous_board);
                         applyMove(move, board, turn);

                         if (isCheck(board, turn)){
                        revertBoard(board, previous_board);
                        continue;
                        }
                        revertBoard(board, previous_board);
                        return 0;;
                        
                    }
                }
            }
        }
    }
    printBoard(board);
;    return 1;

}

void gameLoop(Piece board[8][8], Piece previousBoard[8][8])
{
    Color turn = WHITE;
    Move move;
    while(1)
    {
        printf("\n");
        printBoard(board);
        move = playerMove(turn);
        if(!isLegal(move, board, turn))
        {
            printf("Illegal move, try again.\n");
            continue;
        }
        
        currentBoard(board, previousBoard);
        applyMove(move, board, turn);
        if (isCheck(board, turn)){
            printf("OPEN CHECK, ILLEGAL MOVE!!");
            revertBoard(board, previousBoard);
            continue;
        }

        turn = (turn == WHITE)? BLACK : WHITE;
        if (isCheck(board, turn)){
            printf("CHECK!!");\
            if(hasNoLegalMoves(board,turn))
        {
            printf("Check mate!\n");
            break;
        }
        }
        if(hasNoLegalMoves(board,turn))
        {
            printf("Stalemate!\n");
            break;
        }

    }
}