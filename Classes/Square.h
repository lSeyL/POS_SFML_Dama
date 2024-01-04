//
// Created by seil0 on 4. 1. 2024.
//
#include <SFML/Graphics.hpp>

#ifndef POS_SFML_DAMA_SQUARE_H
#define POS_SFML_DAMA_SQUARE_H


class Square : public sf::Drawable {
private:
    bool black = false;
    bool occupied;
    sf::RectangleShape square;
    sf::FloatRect hitbox;
    int posX;
    int posY;
public:
    Square();

    bool isBlack() const;

    bool isOccupied() const;

    void setOccupied(bool setOccupied);

    void setBlack();

    void changeSize(sf::Vector2f vector2F);

    void changeColor(sf::Color color);

    void setPosition(sf::Vector2f position);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    int getX() const;

    void setX(int setPosX);

    int getY() const;

    void setY(int setPosY);

    sf::Vector2f getSquarePosition() const;

    bool isHit(sf::Vector2f &point) const;

    void updateHitbox();


};


#endif //POS_SFML_DAMA_SQUARE_H
