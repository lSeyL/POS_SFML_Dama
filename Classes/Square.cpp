//
// Created by seil0 on 4. 1. 2024.
//

#include "Square.h"

Square::Square() {
}

bool Square::isBlack() {
    return this->black;
}

bool Square::isOccupied() const{
    return this->occupied;
}

void Square::setBlack() {
    this->black = true;
}

void Square::changeSize(sf::Vector2f vector2F) {
    this->square.setSize(vector2F);
}

void Square::changeColor(sf::Color color) {
    this->square.setFillColor(color);
}
void Square::setPosition(sf::Vector2f position) {
    square.setPosition(position);
}

void Square::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(square, states);
}



