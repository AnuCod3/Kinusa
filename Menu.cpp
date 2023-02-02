//
// Created by anush on 03.01.2023.
//

#include "Menu.h"
#include "Engine.h"
Engine engine;
Menu::Menu() {
    // Lade Hintergrund-Textur
    /*backgroundTexture.loadFromFile("background.png");*/
    background.setTexture(backgroundTexture);

    // Erstelle Buttons
    sf::Text button1;
    button1.setString("Start Game");
    button1.setCharacterSize(24);
    button1.setStyle(sf::Text::Bold);
    button1.setFillColor(sf::Color::White);
    button1.setPosition(100, 100);
    buttons.push_back(button1);

    sf::Text button2;
    button2.setString("Options");
    button2.setCharacterSize(24);
    button2.setStyle(sf::Text::Bold);
    button2.setFillColor(sf::Color::White);
    button2.setPosition(100, 150);
    buttons.push_back(button2);

    sf::Text button3;
    button3.setString("Quit");
    button3.setCharacterSize(24);
    button3.setStyle(sf::Text::Bold);
    button3.setFillColor(sf::Color::White);
    button3.setPosition(100, 200);
    buttons.push_back(button3);
}

void Menu::processInput(sf::Event event) {
// Verarbeite Benutzereingaben
    if (event.type == sf::Event::MouseMoved) {
        // Markiere den Button, auf den der Mauszeiger zeigt, als aktiv
        for (auto &button: buttons) {
            sf::FloatRect buttonRect(button.getPosition(), button.getScale()); // .size) stand da ursprünglich
            if (buttonRect.contains(event.mouseMove.x, event.mouseMove.y))
                button.setFillColor(sf::Color::Red);
            else
                button.setFillColor(sf::Color::White);
        }
    } else if (event.type == sf::Event::MouseButtonReleased) {
        // Prüfe, ob auf einen Button geklickt wurde
        for (auto &button: buttons) {
            sf::FloatRect buttonRect(button.getPosition(), button.getScale());
            if (buttonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                if (button.getString() == "Start Game") {
                    // Starte das Spiel
                } else if (button.getString() == "Options") {
                    // Öffne das Options-Menü
                } else if (button.getString() == "Quit") {
                    // Beende das Programm
                }
            }
        }
    }
}

/*void draw(sf::RenderWindow& window) {
    draw(); // Ein neues Windows erstellen
}*/



/*   Menu::Menu(float width, float height)
{
   if (!font.loadFromFile("../arial.ttf"))
   {
       // handle error
   }

   menu[0].setFont(font);
   menu[0].setColor(sf::Color::Red);
   menu[0].setString("Play");
   menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

   menu[1].setFont(font);
   menu[1].setColor(sf::Color::White);
   menu[1].setString("Options");
   menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

   menu[2].setFont(font);
   menu[2].setColor(sf::Color::White);
   menu[2].setString("Exit");
   menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

   selectedItemIndex = 0;



Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
   for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
   {
       window.draw(menu[i]);
   }
}

void Menu::MoveUp()
{
   if (selectedItemIndex - 1 >= 0)
   {
       menu[selectedItemIndex].setColor(sf::Color::White);
       selectedItemIndex--;
       menu[selectedItemIndex].setColor(sf::Color::Red);
   }
}

void Menu::MoveDown()
{
   if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
   {
       menu[selectedItemIndex].setColor(sf::Color::White);
       selectedItemIndex++;
       menu[selectedItemIndex].setColor(sf::Color::Red);
   }
}

 */