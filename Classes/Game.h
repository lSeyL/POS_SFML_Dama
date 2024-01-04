//
// Created by seil0 on 4. 1. 2024.
//
#include "Board.h"
#include "Player.h"
#include "Pawn.h"
#ifndef POS_SFML_DAMA_GAME_H
#define POS_SFML_DAMA_GAME_H


class Game {
public:
    Game();
    void move(Pawn move);
    void capture(Pawn taker, Pawn captured);

private:
    Board gameBoard;
    Player blue;
    Player red;
};


#endif //POS_SFML_DAMA_GAME_H
