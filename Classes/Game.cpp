//
// Created by seil0 on 4. 1. 2024.
//

#include "Game.h"
/*
Game::Game() {

}

void Game::initializeGame() {
    gameBoard.;
}

void Game::move(Pawn &moved, const sf::Vector2f &positionFrom, const sf::Vector2f &positionTo, int currentPlayerID) {
    if (validMove(moved, positionFrom, positionTo, currentPlayerID)) {

        if (moved.getOwner() != currentPlayerID) {
            std::cerr << "Error: Attempting to move opponent's pawn." << std::endl;
            return;  // Exit the function if the pawn doesn't belong to the current player
        }

        // Update the game board based on the move
        // For simplicity, we assume that the board has a function updateSquare to update the state of a square
        gameBoard.updateSquare(positionFrom.x, positionFrom.y, Square()); // Clear the starting position
        gameBoard.updateSquare(positionTo.x, positionTo.y, moved); // Update the destination position

        // Update the position of the pawn
        moved.setPosition(positionTo);

        // Handle capturing opponents
        handleCapture(positionFrom, positionTo);

        // Handle promoting to kings
        handlePromotion(moved, positionTo.y);

        // Handle multiple jumps
        std::vector<sf::Vector2f> jumpTargets;
        findJumpTargets(positionTo, jumpTargets, currentPlayerID);
        if (!jumpTargets.empty()) {
            // Implement logic to handle multiple jumps
            // This could involve allowing the player to choose the next jump or automatically performing it
            // You might need additional game state tracking for this
        }
        if (jumpTargets.empty()) {
            switchTurn();
        }
    }
}

void Game::handleCapture(const sf::Vector2f &positionFrom, const sf::Vector2f &positionTo) {
    // Simplified logic: Check if there is an opponent's piece at the jumped position
    float jumpedX = (positionFrom.x + positionTo.x) / 2.0f;
    float jumpedY = (positionFrom.y + positionTo.y) / 2.0f;

    if (gameBoard.getSquare(jumpedX, jumpedY).isOccupied()) {
        // Remove the captured opponent's piece from the board
        gameBoard.updateSquare(jumpedX, jumpedY, Square());
    }
}

void Game::handlePromotion(Pawn &moved, float positionToY) {
    // Simplified logic: Promote if the pawn reaches the last row
    if ((moved.getOwner() == 1 && positionToY == 7) || (moved.getOwner() == 2 && positionToY == 0)) {
        moved.promote();
    }
}

bool
Game::isValidJumpTarget(const sf::Vector2f &currentPosition, float targetX, float targetY, int currentPlayerID) const {
    // Check if the target position is within bounds
    if (targetX >= 0 && targetX < gameBoard.getBoardSize() && targetY >= 0 && targetY < gameBoard.getBoardSize()) {
        // Check if the target square is occupied by an opponent's piece
        Square targetSquare = gameBoard.getSquare(static_cast<int>(targetY), static_cast<int>(targetX));
        return targetSquare.getPawn().getOwner() != currentPlayerID && targetSquare.isOccupied();
    }

    // Target position is out of bounds
    return false;
}

void Game::findJumpTargets(const sf::Vector2f &currentPosition, std::vector<sf::Vector2f> &jumpTargets,
                           int currentPlayerID) const {

    // Check the upper-left position
    float targetX = currentPosition.x - 2.0f;
    float targetY = currentPosition.y - 2.0f;
    if (isValidJumpTarget(currentPosition, targetX, targetY, currentPlayerID)) {
        jumpTargets.push_back(sf::Vector2f(targetX, targetY));
    }

    // Check the upper-right position
    targetX = currentPosition.x + 2.0f;
    if (isValidJumpTarget(currentPosition, targetX, targetY, currentPlayerID)) {
        jumpTargets.push_back(sf::Vector2f(targetX, targetY));
    }

    // Check the lower-left position
    targetY = currentPosition.y + 2.0f;
    if (isValidJumpTarget(currentPosition, currentPosition.x - 2.0f, targetY, currentPlayerID)) {
        jumpTargets.push_back(sf::Vector2f(currentPosition.x - 2.0f, targetY));
    }

    // Check the lower-right position
    targetX = currentPosition.x + 2.0f;
    if (isValidJumpTarget(currentPosition, targetX, targetY, currentPlayerID)) {
        jumpTargets.push_back(sf::Vector2f(targetX, targetY));
    }
}

void Game::switchTurn() {
    // Switch turns between player 1 (blue) and player 2 (red)
    currentPlayerID = (currentPlayerID == 1) ? 2 : 1;
}

bool Game::isValidPosition(const sf::Vector2f &position) const {
    return position.x >= 0 && position.x < gameBoard.getBoardSize() &&
           position.y >= 0 && position.y < gameBoard.getBoardSize();
}

bool Game::validMove(const Pawn &moved, const sf::Vector2f &positionFrom, const sf::Vector2f &positionTo,
                     int currentPlayerID) const {

    if (positionTo.x < 0 || positionTo.x >= gameBoard.getBoardSize() || positionTo.y < 0 ||
        positionTo.y >= gameBoard.getBoardSize()) {
        return false;
    }
    if (gameBoard.getSquare(positionTo.x, positionTo.y).isOccupied()) {
        return false;
    }
    float deltaX = std::abs(positionTo.x - positionFrom.x);
    float deltaY = std::abs(positionTo.y - positionFrom.y);

    if (deltaX != deltaY) {
        return false;
    }
    if (deltaX == 1 && !moved.getPromotionStatus()) {
        // check ktorým smerom sa majú pohybovať
        int direction = 0;
        if (currentPlayerID == 1) {
            direction = 1;
        } else {
            direction = -1;
        }


        if (deltaY != direction) {
            return false;
        }
    }
    if (deltaX == 2) {
        sf::Vector2f jumpedPosition(
                (positionFrom.x + positionTo.x) / 2.0f,
                (positionFrom.y + positionTo.y) / 2.0f
        );

        // Check if there is an opponent's piece at the jumped position
        if (!gameBoard.getSquare(jumpedPosition.x, jumpedPosition.y).isOccupied()) {
            return false;
        }
    }

    return true;
}

*/

