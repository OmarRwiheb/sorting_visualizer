#include<SFML/Graphics.hpp>
#include<vector>
#include<stdlib.h>
#include"Draw.h"
#include"sortingAlgorithms.h"
#include<time.h>
#include<iostream>

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

    srand(0);

    std::vector<sf::RectangleShape> shape(50);
    makeTheShapes(shape);

    sortType sort; 

    int selection = 0;
   
    std::cout << "Please select the sorting algorithm: \n";
    std::cout << "1- bubble sort\n2- selection sort\n";
    std::cin >> selection;
    
    sf::RenderWindow window(sf::VideoMode(1500, 800), "Bubble Sort");
    switch (selection)
    {
    case 1: 
        while (window.isOpen()) {
            sort.BubbleSort(shape, window);
        }
    case 2:
        while (window.isOpen()) {
            sort.SelectionSort(shape, window);
        }
    default:
        cout << "invalid choice.\n";
        break;
    }

 

    return EXIT_SUCCESS;
}
