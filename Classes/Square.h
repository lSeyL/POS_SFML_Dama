//
// Created by seil0 on 4. 1. 2024.
//
#include <SFML/Graphics.hpp>
#ifndef POS_SFML_DAMA_SQUARE_H
#define POS_SFML_DAMA_SQUARE_H


class Square : public sf::Drawable{
private:
    bool black = false;
    bool occupied;
    sf::RectangleShape square;
public:
    Square();
    bool isBlack();
    bool isOccupied();
    void setBlack();
    void changeSize(sf::Vector2f vector2F);
    void changeColor(sf::Color color);
    void setPosition(sf::Vector2f position);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //POS_SFML_DAMA_SQUARE_H
