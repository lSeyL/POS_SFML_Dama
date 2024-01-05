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
    void move(Pawn &moved, const sf::Vector2f &positionFrom, const sf::Vector2f &positionTo, int currentPlayerID);
    bool validMove(const Pawn& moved, const sf::Vector2f& positionFrom, const sf::Vector2f& positionTo, int currentPlayerID) const;
    void handleCapture(const sf::Vector2f &positionFrom, const sf::Vector2f &positionTo);
    void handlePromotion(Pawn &moved, float positionToY);
    bool isValidJumpTarget(const sf::Vector2f &currentPosition, float targetX, float targetY, int currentPlayerID) const;
    void findJumpTargets(const sf::Vector2f &currentPosition, std::vector<sf::Vector2f> &jumpTargets, int currentPlayerID) const;

private:
    Board gameBoard;
    Player blue;
    Player red;

};


#endif //POS_SFML_DAMA_GAME_H
