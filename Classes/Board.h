//
// Created by seil0 on 4. 1. 2024.
//

#include "Square.h"
#include "Pawn.h"

#ifndef POS_SFML_DAMA_BOARD_H
#define POS_SFML_DAMA_BOARD_H


class Board {
private:
    static const int boardSize = 8;
    Square squares[boardSize][boardSize];
    std::vector<Pawn> pawnsWhite;
    std::vector<Pawn> pawnsBlack;
public:
    Board();

    static int getBoardSize();

    Square &getSquare(int i, int j);

    std::vector<Pawn> &getPawnBlack();

    std::vector<Pawn> &getPawnWhite();

    using SquareArray = const Square (&)[boardSize][boardSize];

};


#endif //POS_SFML_DAMA_BOARD_H
