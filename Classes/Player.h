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
public:
    Player(int id);
    void setBoard(Board board);
    void setPieces(std::vector<Pawn> playerPieces);
    int getPlayerId();
    void setPlayerId(int id);
};


#endif //POS_SFML_DAMA_PLAYER_H
