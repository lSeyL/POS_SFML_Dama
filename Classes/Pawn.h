//
// Created by seil0 on 4. 1. 2024.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef POS_SFML_DAMA_PAWN_H
#define POS_SFML_DAMA_PAWN_H


class Pawn : public sf::Drawable {
private:
    bool black = false;
    bool selected = false;
    bool promoted = false;
    sf::CircleShape pawn;
    sf::FloatRect hitbox;
public:
    Pawn();
    bool isBlack();
    void setBlack();
    bool isSelected() const;
    void setSelected(bool select);
    bool isHit(sf::Vector2f& point) const;
    void changeSize(float radius);
    void changeColor(sf::Color color);
    void setPosition(sf::Vector2f position);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void updateHitbox();
};


#endif //POS_SFML_DAMA_PAWN_H
