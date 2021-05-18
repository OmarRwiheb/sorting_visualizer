#pragma once
#include<SFML/Graphics.hpp>

class DrawShape {
public:
    void Close(sf::RenderWindow& window);
    void DrawBubble(std::vector<sf::RectangleShape>& shape, sf::RenderWindow& window, size_t i);
    void DrawSelection(std::vector<sf::RectangleShape>& shape, sf::RenderWindow& window, size_t i);
};

void DrawShape::Close(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    //to close the window when we press escape 
    bool Retry(false);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        Retry = true;
    }
    if (Retry) {
        window.close();
    }
}
void DrawShape::DrawBubble(std::vector<sf::RectangleShape>& shape, sf::RenderWindow& window, size_t i) {

    for (size_t k = 0; k < 50; k++) {
        window.draw(shape[k]);
        shape[k].setFillColor(sf::Color::White);
        if (k > 50 - i - 1)
            shape[k].setFillColor(sf::Color::Green);
    }
    Close(window);
}

void DrawShape::DrawSelection(std::vector<sf::RectangleShape>& shape, sf::RenderWindow& window, size_t i) {

    for (size_t k = 0; k < 50; k++) {
        window.draw(shape[k]);
        shape[k].setFillColor(sf::Color::White);
        if (k == i)
            shape[k].setFillColor(sf::Color::Red);
    }
    Close(window);
}

