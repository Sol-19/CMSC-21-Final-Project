#include "./chess_utils.h"
#include "./chess_struct.h"
#include <stdio.h>

void setBoard(Piece board [8][8])
{

    //Normal Board
    board[0][0].type = ROOK; board[0][0].color = BLACK;
    board[0][1].type = KNIGHT; board[0][1].color = BLACK;
    board[0][2].type = BISHOP; board[0][2].color = BLACK;
    board[0][3].type = QUEEN; board[0][3].color = BLACK;
    board[0][4].type = KING; board[0][4].color = BLACK;
    board[0][5].type = BISHOP; board[0][5].color = BLACK;
    board[0][6].type = KNIGHT; board[0][6].color = BLACK;
    board[0][7].type = ROOK; board[0][7].color = BLACK;

    board[7][0].type = ROOK; board[7][0].color = WHITE;
    board[7][1].type = KNIGHT; board[7][1].color = WHITE;
    board[7][2].type = BISHOP; board[7][2].color = WHITE;
    board[7][3].type = QUEEN; board[7][3].color = WHITE;
    board[7][4].type = KING; board[7][4].color = WHITE;
    board[7][5].type = BISHOP; board[7][5].color = WHITE;
    board[7][6].type = KNIGHT; board[7][6].color = WHITE;
    board[7][7].type = ROOK; board[7][7].color = WHITE;

    for (int i = 0; i < 8; i++) {
         board[1][i].type = PAWN; board[1][i].color = BLACK;
         board[6][i].type = PAWN; board[6][i].color = WHITE;
     }

    // //En passant setup
    // board[7][4].type = KING; 
    // board[7][4].color = WHITE;
    // board[0][4].type = KING; 
    // board[0][4].color = BLACK;

    // for (int i = 0; i < 8; i++) {
    //      board[1][i].type = PAWN; board[1][i].color = BLACK;
    //      board[6][i].type = PAWN; board[6][i].color = WHITE;
    //  }

    // //Pin promotion setup, remove rook for promotion
    // board[1][0].type = KING; 
    // board[1][0].color = WHITE;
    // board[1][1].type = PAWN;
    // board[1][1].color = WHITE;
    // board[0][4].type = KING; 
    // board[0][4].color = BLACK;
    // board[1][7].type = ROOK;
    // board[1][7].color = BLACK;


    // //Stalemate/Checkmate setup
    // board[7][4].type = KING; 
    // board[7][4].color = WHITE;
    // board[1][0].type = ROOK;
    // board[1][0].color = WHITE;
    // board[2][5].type = QUEEN;
    // board[2][5].color = WHITE;
    // board[0][7].type = KING; 
    // board[0][7].color = BLACK;

    

 
}




