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
    this->pawn.setRadius(radius);
}

void Pawn::changeColor(sf::Color color) {
    this->pawn.setFillColor(color);
}
void Pawn::setPosition(sf::Vector2f position) {
    pawn.setPosition(position);
}


void Pawn::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(pawn, states);
}

bool Pawn::isHit(sf::Vector2f& point) const {
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
    if(this->selected) {
        this->pawn.setOutlineColor(sf::Color::Magenta);
        this->pawn.setOutlineThickness(1.5);
    } else {
        this->pawn.setOutlineThickness(0);
    }
}

void Pawn::promote() {
    this->promoted = true;
}

void Pawn::setOwner(Player owningPlayer) {
    this->owner = owningPlayer.getPlayerId();
}

int Pawn::getOwner() const {
    return this->owner;
}

