#include <SFML/Graphics.hpp>
#include "Player.h"
#include <math.h>
#include <iostream>
using namespace std;
using namespace sf;


int main()
{
    RenderWindow window(VideoMode(1280, 720), "Fake Mario by Anusan and Kilian");
    Player one;

    float speed = 0.f;

    // Setze die Schwerkraft
    float gravity = 7.81f;

    // Setze die maximale Fallgeschwindigkeit
    float maxFallSpeed = 50.f;

    // Setze die Sprungkraft
    float jumpPower = 45.f;

    // Setze eine Flag, um zu überprüfen, ob der Spieler auf dem Boden ist
    bool isOnGround = true;


    sf::Clock clock;

    while (window.isOpen()) // push test
    {
        Event event;
        while (window.pollEvent(event))
        {
            //if(one.getPositionY()<=500) one.setPosition(one.getPositionX(), 200);

            if (event.type == Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && isOnGround)
            {
                speed = -jumpPower;
                isOnGround = false;
                cout << "/*u*/\n";
                cout << "Y = " << one.getPositionY() << "\n";
            }



            // Player Movement
            if(Keyboard::isKeyPressed(Keyboard::A)) one.moveLeft();
            if(Keyboard::isKeyPressed(Keyboard::D)) one.moveRight();
            //if(Keyboard::isKeyPressed(Keyboard::W)) one.moveUp();
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

            // Berechne die verstrichene Zeit seit dem letzten Frame
            //float dt = clock.restart().asSeconds();

            //one.update(one, dt); // Aktualisiere den Spieler

           //one.setPosition(x, y);

        }

        one.setPosition(one.getPositionX(),(one.getPositionY()+speed));
        speed += gravity;

        cout << "Y Nach Jump = " << one.getPositionY() << "\n";

        // Begrenze die Fallgeschwindigkeit
        if (speed > maxFallSpeed)
            speed = maxFallSpeed;

        // Wenn der Spieler den Boden berührt, setze die y-Position auf dem Boden und setze die Flag auf true
        if (one.getPositionY() > 480)
        {
            one.setPosition(one.getPositionX(),480);
            //one.setPositionY(480);
            isOnGround = true;
        }

        // Setze die neue Position des Spielers
        one.setPosition(one.getPositionX(), one.getPositionY());

        cout << "Letztes Y = " << one.getPositionY() << "\n";

        window.clear(Color::White);
        window.draw(one.getSprite());
        window.display();

    }
    return 0;
}