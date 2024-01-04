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
    void inicializeGame();
    void move(Pawn moved, sf::Vector2f positionFrom, sf::Vector2f positionTo);
    void capture(Pawn taker, Pawn captured, sf::Vector2f positionFrom, sf::Vector2f positionCaptured, sf::Vector2f positionTo);

    bool validMove(const Pawn& moved, const sf::Vector2f& positionFrom, const sf::Vector2f& positionTo, int currentPlayerID) const;
private:
    Board gameBoard;
    Player blue;
    Player red;
};


#endif //POS_SFML_DAMA_GAME_H
