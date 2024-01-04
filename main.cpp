#include <iostream>
#include <SFML/Graphics.hpp>
#include "Classes/Square.h"
#include "Classes/Board.h"
int main() {
    sf::RenderWindow window(sf::VideoMode(800,800),"SFML");
    Board board;

    while(window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                    // Reset colors for all pawns
                    for (auto& pawn : board.getPawnBlack()) {
                        pawn.setSelected(false);
                        pawn.changeColor(sf::Color::Red);
                    }

                    for (auto& pawn : board.getPawnWhite()) {
                        pawn.setSelected(false);
                        pawn.changeColor(sf::Color::Blue);
                    }

                    // Check if any pawn was clicked and update its color
                    for (auto& pawn : board.getPawnBlack()) {
                        if (pawn.isHit(mousePosition)) {
                            pawn.setSelected(true);
                            std::cout << "Black\n";
                            pawn.changeColor(sf::Color::Magenta);
                            break;
                        }
                    }

                    for (auto& pawn : board.getPawnWhite()) {
                        if (pawn.isHit(mousePosition)) {
                            pawn.setSelected(true);
                            std::cout << "White\n";
                            pawn.changeColor(sf::Color::Magenta);
                            break;
                        }
                    }
                }
            }
        }

        window.clear();

        for (int i = 0; i < board.getBoardSize(); ++i) {
            for (int j = 0; j < board.getBoardSize(); ++j) {
                window.draw(board.getSquare(i,j));
            }
        }

        for (auto& pawn : board.getPawnBlack()) {
            window.draw(pawn);
        }
        for (auto& pawn : board.getPawnWhite()) {
            window.draw(pawn);
        }
        window.display();

    }

    return 0;
}
