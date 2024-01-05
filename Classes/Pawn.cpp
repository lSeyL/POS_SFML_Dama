//
// Created by seil0 on 4. 1. 2024.
//

#include "Pawn.h"

Pawn::Pawn() {
    updateHitbox();
}

bool Pawn::isBlack() {
    return this->black;
}

void Pawn::setBlack() {
    this->black = true;
}

void Pawn::changeSize(float radius) {
    sf::Vector2f currentPosition = getPosition();
    this->pawn.setRadius(radius);
    this->pawn.setOrigin(currentPosition);
    //this->pawn.setPosition(currentPosition);
    updateHitbox();
}

void Pawn::changeColor(sf::Color color) {
    this->pawn.setFillColor(color);
}

void Pawn::setPosition(sf::Vector2f position) {
    this->pawn.setPosition(position);
}


void Pawn::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(pawn, states);
}

bool Pawn::isHit(sf::Vector2f &point) const {
    return hitbox.contains(point);
}

void Pawn::updateHitbox() {
    hitbox = pawn.getGlobalBounds();
}

bool Pawn::isSelected() const {
    return this->selected;
}

void Pawn::setSelected(bool select) {
    this->selected = select;
    if (this->selected) {
        this->pawn.setOutlineColor(sf::Color::Magenta);
        this->pawn.setOutlineThickness(1.5);
    } else {
        this->pawn.setOutlineThickness(0);
    }
}

sf::Vector2f Pawn::getPosition() const {
    return this->pawn.getPosition();
}

int Pawn::getX() const {
    return posX;
}

void Pawn::setX(int setPosX) {
    posX = setPosX;
}

int Pawn::getY() const {
    return posY;
}

void Pawn::setY(int setPosY) {
    posY = setPosY;
}

void Pawn::promote() {
    this->promoted = true;
}

void Pawn::setOwner(int owner) {
    this->owner = owner;
}

int Pawn::getOwner() {
    return this->owner.getPlayerId();
}
