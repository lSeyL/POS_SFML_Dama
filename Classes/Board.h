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
    int getBoardSize();
    const Square& getSquare(int i, int j) const;
    std::vector<Pawn>& getPawnBlack();
    std::vector<Pawn>& getPawnWhite();
};


#endif //POS_SFML_DAMA_BOARD_H
