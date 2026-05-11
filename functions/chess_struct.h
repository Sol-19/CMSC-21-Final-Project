#ifndef CHESS_STRUCT_H
#define CHESS_STRUCT_H
    typedef enum{ EMPTY = 0, PAWN = 1, BISHOP = 2, KNIGHT = 3, ROOK = 4, QUEEN = 5, KING = 6} PieceType;
    typedef enum{ BLACK = -1, NONE = 0, WHITE = 1 } Color;
    typedef enum{ NORMAL = 0, CASTLE_KINGSIDE = 1, CASTLE_QUEENSIDE = 2} MoveType;
    
    typedef struct{
        PieceType type;
        Color color;
        int move_count;
    }Piece;

    typedef struct{
        int from_x, from_y;
        int to_x, to_y;
        MoveType type;
    } Move;

#endif


