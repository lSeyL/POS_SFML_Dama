//
// Created by seil0 on 4. 1. 2024.
//

#include "Game.h"

void Game::inicializeGame() {

}

void Game::move(Pawn moved, sf::Vector2f positionFrom, sf::Vector2f positionTo) {

}

void Game::capture(Pawn taker, Pawn captured, sf::Vector2f positionFrom, sf::Vector2f positionCaptured,
                   sf::Vector2f positionTo) {

}

bool Game::validMove(const Pawn& moved, const sf::Vector2f& positionFrom, const sf::Vector2f& positionTo, int currentPlayerID) const{

    if (positionTo.x < 0 || positionTo.x >= gameBoard.getBoardSize() || positionTo.y < 0 || positionTo.y >= gameBoard.getBoardSize()) {
        return false;
    }
    if ( gameBoard.getSquare(positionTo.x, positionTo.y).isOccupied()) {
        return false;
    }
    float deltaX = std::abs(positionTo.x - positionFrom.x);
    float deltaY = std::abs(positionTo.y - positionFrom.y);

    if (deltaX != deltaY) {
        return false;
    }
    if (deltaX == 1) {
        // check ktorým smerom sa majú pohybovať
        int direction = 0;
        if (currentPlayerID == 1)
        {
            direction = 1;
        }
        else
        {
            direction = -1;
        }

        // For simplicity, this example assumes that the piece can move in any direction
        if (deltaY == direction) {
            return true;
        }
    }
    if (deltaX == 2) {
        sf::Vector2f jumpedPosition(
                (positionFrom.x + positionTo.x) / 2.0f,
                (positionFrom.y + positionTo.y) / 2.0f
        );

        // Check if there is an opponent's piece at the jumped position
        if (gameBoard.getSquare(jumpedPosition.x, jumpedPosition.y).isOccupied()) {
            return true;
        }
    }

    // Check for kinging



    return false;
}


