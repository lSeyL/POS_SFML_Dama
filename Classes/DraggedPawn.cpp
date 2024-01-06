//
// Created by seil0 on 6. 1. 2024.
//

#include <valarray>
#include "DraggedPawn.h"

DraggedPawn::DraggedPawn() {
    this->draggedPawn.setRadius(radius);
}

void DraggedPawn::setDragged(bool setDragged) {
    this->dragged = setDragged;
    setDraggedColor();

}

void DraggedPawn::setDraggedColor() {
    if (isDragged()) {
        this->draggedPawn.setFillColor(sf::Color::Green);
    } else {
        this->draggedPawn.setFillColor(sf::Color::Transparent);
    }
}


bool DraggedPawn::isDragged() {
    return this->dragged;
}

sf::CircleShape DraggedPawn::getMainShape() {
    return this->draggedPawn;
}

void DraggedPawn::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(draggedPawn, states);
}

void DraggedPawn::updatePosition(const sf::RenderWindow &window) {
    if (isDragged()) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        draggedPawn.setPosition(static_cast<float>(mousePosition.x) - radius,
                                static_cast<float>(mousePosition.y) - radius);
    }
}


