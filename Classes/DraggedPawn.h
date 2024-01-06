//
// Created by seil0 on 6. 1. 2024.
//

#ifndef POS_SFML_DAMA_DRAGGEDPAWN_H
#define POS_SFML_DAMA_DRAGGEDPAWN_H

#include "Pawn.h"

class DraggedPawn : public sf::Drawable {
private:
    sf::CircleShape draggedPawn;
    bool dragged = false;
    float radius = 35;
public:
    DraggedPawn();

    void setDragged(bool setDragged);

    void setDraggedColor();

    bool isDragged();

    sf::CircleShape getMainShape();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void updatePosition(const sf::RenderWindow &window);
};


#endif //POS_SFML_DAMA_DRAGGEDPAWN_H
