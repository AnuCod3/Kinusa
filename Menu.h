//
// Created by anush on 03.01.2023.
//

#ifndef MARIO_MENU_H
#define MARIO_MENU_H
#define MAX_NUMBER_OF_ITEMS 3

#endif //MARIO_MENU_H

#include "SFML/Graphics.hpp"
#include <vector>

class Menu
{
public:
    Menu();
    void processInput(sf::Event event);
    void update();
    void draw(sf::RenderWindow& window);

private:
    std::vector<sf::Text> buttons;
    sf::Sprite background;
    sf::Texture backgroundTexture;
};


/*class Menu
{
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};*/