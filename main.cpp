#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <chrono>
using namespace std;
using namespace sf;

const int WIDTH = 1280;
const int HEIGHT = 720;

using namespace std;
using namespace sf;

int main(){
    RenderWindow gameWindow (VideoMode(WIDTH, HEIGHT), "Marioo by Anusan and Kilian");
    gameWindow.setFramerateLimit(60);

    Texture playeroneTexture;
    playeroneTexture.loadFromFile("C:\\Users\\anush\\CLionProjects\\Marioi\\Wraith_03_Idle_000.png");

    Sprite playeroneSprite;
    playeroneSprite.setTexture(playeroneTexture);
    playeroneSprite.setPosition(0, 500);
    playeroneSprite.setScale(0.5, 0.5);

    //--//
    Player playerone;
    while (gameWindow.isOpen()){
        Event event;
        while (gameWindow.pollEvent(event)){
            if (event.type == Event::Closed){
                gameWindow.close();
            }

            if(Keyboard::isKeyPressed(Keyboard::A)) {
                playeroneSprite.move(-2.0, 0);
            }

            if(Keyboard::isKeyPressed(Keyboard::D)) {
                playeroneSprite.move(2.0, 0);
            }

            if(Keyboard::isKeyPressed(Keyboard::Space) && !playerone.getIsJump()) {
                playeroneSprite.move(0, -2.0);
                playerone.setIsJump(true);
                }

            if(playeroneSprite.getPosition().y > 500) {
                playeroneSprite.setPosition(playeroneSprite.getPosition().x, 500);
                playerone.setIsJump(false); //Shaisa baustelle jump nix funktion
            }
           /* if(playeroneSprite.getPosition().x > 499) {
                playerone.setIsJump(false);
                playeroneSprite.setPosition(playeroneSprite.getPosition().x,500);
            }*/
        }

        gameWindow.clear(Color::Magenta);
        gameWindow.draw(playeroneSprite);
        gameWindow.display();
    }
    return 0;
}

