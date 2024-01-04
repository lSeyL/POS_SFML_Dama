//
// Created by seil0 on 4. 1. 2024.
//

#ifndef POS_SFML_DAMA_PLAYER_H
#define POS_SFML_DAMA_PLAYER_H
#include "Pawn.h"
#include "vector"
#include "Board.h"

class Player {
private:
    int playerId;
    Board gameBoard;
    std::vector<Pawn> pieces;
    bool notValidMove;
public:
    Player();
    void setBoard(Board gameBoard);
    void getPieces(std::vector<Pawn> pieces);

};


#endif //POS_SFML_DAMA_PLAYER_H
