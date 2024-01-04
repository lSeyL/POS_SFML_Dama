//
// Created by seil0 on 4. 1. 2024.
//

#include "Square.h"

Square::Square() {
    this->occupied = false;
}

bool Square::isBlack() const {
    return this->black;
}

bool Square::isOccupied() const {
    return occupied;
}

void Square::setOccupied(bool setOccupied) {
    occupied = setOccupied;
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

void Square::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(square, states);
}

int Square::getX() const {
    return posX;
}

void Square::setX(int setPosX) {
    posX = setPosX;
}

int Square::getY() const {
    return posY;
}

void Square::setY(int setPosY) {
    posY = setPosY;
}

sf::Vector2f Square::getSquarePosition() const {
    return square.getPosition();
}

bool Square::isHit(sf::Vector2f &point) const {
    return hitbox.contains(point);
}

void Square::updateHitbox() {
    hitbox = square.getGlobalBounds();
}





