//
// Created by seil0 on 4. 1. 2024.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

#ifndef POS_SFML_DAMA_PAWN_H
#define POS_SFML_DAMA_PAWN_H




class Pawn : public sf::Drawable {
private:
    bool black = false;
    bool selected = false;
    bool promoted = false;
    Player owner;
    sf::CircleShape pawn;
    sf::FloatRect hitbox;
    int posX;
    int posY;
public:
    Pawn();

    bool isBlack();

    void setBlack();

    bool isSelected() const;

    void setSelected(bool select);

    bool isHit(sf::Vector2f &point) const;

    void updateHitbox();

    void changeSize(float radius);

    void changeColor(sf::Color color);

    void setPosition(sf::Vector2f position);

    sf::Vector2f getPosition() const;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    int getX() const;

    void setX(int setPosX);

    int getY() const;

    void setY(int setPosY);

    void promote();

    void setOwner(Player owner);

    int getOwner();
};

#endif //POS_SFML_DAMA_PAWN_H
