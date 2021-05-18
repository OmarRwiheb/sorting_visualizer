#include<SFML/Graphics.hpp>
#include<vector>
#include<stdlib.h>
#include"Draw.h"
#include"sortingAlgorithms.h"
#include<time.h>

//makeTheShapes function is used to create the columns that we will sort
//by making a vector of rectangles and give each rectangle position and width and random highet between 1 and 700
void makeTheShapes(std::vector<sf::RectangleShape>& shape) {
    for (int i = 0; i < 50; i++) {
        shape[i].setSize(sf::Vector2f(24, rand() % 700 + 1));
        shape[i].setFillColor(sf::Color::White);
        shape[i].setOutlineColor(sf::Color::Cyan);
        shape[i].setOutlineThickness(2);
        shape[i].setPosition(30 + i * 30, 800);
        shape[i].setRotation(180);
    }
}

int main() {

    sf::RenderWindow window(sf::VideoMode(1500, 800), "Bubble Sort");

    std::vector<sf::RectangleShape> shape(50);
    makeTheShapes(shape);

    sortType sortType;

    while (window.isOpen()) {
       sortType.BubbleSort(shape, window);
       //sortType.SelectionSort(shape, window);
    }

    return EXIT_SUCCESS;
}