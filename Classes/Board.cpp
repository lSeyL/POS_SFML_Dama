//
// Created by seil0 on 4. 1. 2024.
//

#include "Board.h"

Board::Board(){
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            this->squares[i][j].changeSize(sf::Vector2f(100, 100));

            // Set the color based on the position to create a checker pattern
            if ((i + j) % 2 == 0) {
                this->squares[i][j].changeColor(sf::Color::White);
            } else {
                this->squares[i][j].changeColor(sf::Color::Black);
                this->squares[i][j].setBlack();
            }

            this->squares[i][j].setPosition(sf::Vector2f(j * 100, i * 100));

            if (this->squares[i][j].isBlack() && i < 2) {
                Pawn pawn;
                pawn.changeSize(50);
                pawn.changeColor(sf::Color::Red);
                pawn.setPosition(sf::Vector2f(j * 100, i * 100));
                pawn.updateHitbox();
                pawn.setBlack();

                pawnsBlack.push_back(pawn);
            } else if(this->squares[i][j].isBlack() && i >= boardSize - 2 ) {
                Pawn pawn;
                pawn.changeSize(50);
                pawn.changeColor(sf::Color::Blue);
                pawn.setPosition(sf::Vector2f(j * 100, i * 100));
                pawn.updateHitbox();

                pawnsWhite.push_back(pawn);
            }
        }
    }
}



int Board::getBoardSize() {
    return boardSize;
}

const Square &Board::getSquare(int i, int j) const {
    return  this->squares[i][j];
}

std::vector<Pawn>& Board::getPawnBlack() {
    return this->pawnsBlack;
}

std::vector<Pawn>& Board::getPawnWhite() {
    return this->pawnsWhite;
}


