#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include"Draw.h"

class sortType {
    DrawShape drawObject;
public:
    void BubbleSort(std::vector<sf::RectangleShape>& shape, sf::RenderWindow& window);
    void SelectionSort(std::vector<sf::RectangleShape>& shape, sf::RenderWindow& window);
};

void sortType::BubbleSort(std::vector<sf::RectangleShape>& shape, sf::RenderWindow& window) {
    for (size_t i = 0; i < 50; i++) {
        for (size_t j = 0; j < 50 - i - 1; j++) {

            //to give the current column red color
            shape[j + 1].setFillColor(sf::Color::Red);
            shape[j].setFillColor(sf::Color::White);

            //to swap two columns if the first higher than the second
            if (shape[j].getSize().y > shape[j + 1].getSize().y) {
                int temp = shape[j].getSize().y;
                shape[j].setSize(sf::Vector2f(24, shape[j + 1].getSize().y));
                shape[j + 1].setSize(sf::Vector2f(24, temp));
            }

            window.clear();
            //draw function is used to display columns on the screen
            drawObject.DrawBubble(shape, window, i);
            window.setFramerateLimit(60);
            window.display();
        }
    }
}

void sortType::SelectionSort(std::vector<sf::RectangleShape>& shape, sf::RenderWindow& window) {

    for (size_t i = 0; i < 50 - 1; i++) {
        size_t minimum = i;
        for (size_t j = i + 1; j < 50; j++) {

            ////to give the current column red color
            if(j < 50 - 1)
            shape[j + 1].setFillColor(sf::Color::Red);
            shape[j].setFillColor(sf::Color::White);

            //to swap two columns if the first higher than the second
            if (shape[j].getSize().y < shape[minimum].getSize().y) {
                minimum = j;
            }

            window.clear();
            //draw function is used to display columns on the screen
            drawObject.DrawSelection(shape, window, i);
            window.setFramerateLimit(60);
            window.display();

        }
        int temp = shape[i].getSize().y;
        shape[i].setSize(sf::Vector2f(24, shape[minimum].getSize().y));
        shape[minimum].setSize(sf::Vector2f(24, temp));
    }
}
