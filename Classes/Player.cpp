//
// Created by seil0 on 4. 1. 2024.
//

#include "Player.h"

Player::Player(int id) {
    this->playerId = id;
}

void Player::setBoard(Board board) {
    this->gameBoard = board;
}

void Player::setPieces(std::vector<Pawn> playerPieces) {
    this->pieces = playerPieces;
}

int Player::getPlayerId() {
    return playerId;
}

void Player::setPlayerId(int id) {
    this->playerId = id;
}
