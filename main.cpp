#include <iostream>
#include <chrono>
#include <ctime>

#include <SFML/Graphics.hpp>
#include "Classes/Square.h"
#include "Classes/Board.h"
#include "Classes/DraggedPawn.h"

void move(Board &board, Pawn &pawn, const sf::Vector2f &destination) {
    int destRow = static_cast<int>(destination.y / 100);
    int destCol = static_cast<int>(destination.x / 100);
    if (board.getSquare(destRow, destCol).isBlack()) {
        if (!board.getSquare(destRow, destCol).isOccupied()) {
            sf::Vector2f squarePosition = board.getSquare(destRow, destCol).getSquarePosition();
            int squarePositionX = squarePosition.x;
            int squarePositionY = squarePosition.y;
            int squareRow = pawn.getX();
            int squareCol = pawn.getY();
            board.getSquare(squareCol, squareRow).setOccupied(false);

            int posX = board.getSquare(destRow, destCol).getX();
            int posY = board.getSquare(destRow, destCol).getY();
            pawn.setPosition(squarePosition);
            pawn.setY(posY);
            pawn.setX(posX);
            pawn.updateHitbox();

            //Occupy
            board.getSquare(destRow, destCol).setOccupied(true);


            //Delete old occupation


        } else {
            std::cout << "Square is already occupied.\n";
        }

    } else {
        std::cout << "White square.\n";
    }

}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML");
    bool isFirstClick = true;
    Board board;
    DraggedPawn dp;
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(
                            sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

                    for (auto &pawn: board.getPawnWhite()) {
                        pawn.setSelected(false);
                        pawn.changeColor(sf::Color::Blue);
                        pawn.getMainShape().setOutlineThickness(0.f);
                    }

                    for (auto &pawn: board.getPawnWhite()) {
                        if (pawn.isHit(mousePosition)) {
                            if (isFirstClick) {
                                pawn.setSelected(true);
                                pawn.changeColor(sf::Color::Transparent);
                                pawn.getMainShape().setOutlineColor(sf::Color::Magenta);
                                pawn.getMainShape().setOutlineThickness(3.f);
                                isFirstClick = false;
                                dp.setDragged(true);
                                break;
                            }

                        }
                    }

                }

            } else if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    dp.setDragged(false);
                    for (auto &pawn: board.getPawnWhite()) {
                        if (pawn.isSelected()) {
                            if (!isFirstClick) {
                                pawn.setSelected(false);
                                sf::Vector2f mousePositionNew = window.mapPixelToCoords(
                                        sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                                move(board, pawn, mousePositionNew);
                                isFirstClick = true;
                                pawn.changeColor(sf::Color::Blue);
                                dp.setDragged(false);

                                break;
                            }

                        }
                    }

                }

            }

            /*
            auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            char timeString[100];
            std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));
            std::cout << "test " << timeString << std::endl;
            */
            window.clear();

            for (int i = 0; i < board.getBoardSize(); ++i) {
                for (int j = 0; j < board.getBoardSize(); ++j) {
                    window.draw(board.getSquare(i, j));
                }
            }

            for (auto &pawn: board.getPawnBlack()) {
                window.draw(pawn);
            }
            for (auto &pawn: board.getPawnWhite()) {
                window.draw(pawn);
            }

            dp.updatePosition(window);
            window.draw(dp);


            window.display();

        }


    }
    return 0;
}

