#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1280, 720), "Fake Mario by Anusan and Kilian");
    Player one;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            //if(one.getPositionY()<=500) one.setPosition(one.getPositionX(), 200);

            if (event.type == Event::Closed)
                window.close();

            // Player Movement
            if(Keyboard::isKeyPressed(Keyboard::A)) one.moveLeft();
            if(Keyboard::isKeyPressed(Keyboard::D)) one.moveRight();
            if(Keyboard::isKeyPressed(Keyboard::W)) one.moveUp();
            //if(!Keyboard::isKeyPressed(Keyboard::W)) one.moveDown(); // scheisse code

            // Player Border
            if(one.getPositionX() >= window.getSize().x-85) {
                one.setPosition(window.getSize().x-85 , one.getPositionY());
            }

            if (one.getPositionX() <= -25) { // x-Border-Left
                one.setPosition(-25, one.getPositionY());
            }

            if(one.getPositionY() >= window.getSize().y-20) {
                one.setPosition(one.getPositionX(), window.getSize().y-50);
            }

            if (one.getPositionY() <= 0) { // y-Border-Bottom
                one.setPosition(one.getPositionX(), 0);
            }

        }

        window.clear(Color::White);
        window.draw(one.getSprite());
        window.display();

    }
    return 0;
}