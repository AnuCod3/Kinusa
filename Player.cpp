#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Engine.h"
#include <iostream>
using namespace std;
Engine engine;
Player::Player(){
    speed = 100;
    playerTexture.loadFromFile("../PlayerTexture.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(200, 800);
    playerSprite.setScale(0.45, 0.45);
    velocity.x = 8;
    velocity.y = 8;
    Leftpressed = false;
    Rightpressed = false;
    Uppressed = false;

    /*testRect.setPosition(800,800);
    testRect.setFillColor(sf::Color::Red);
    testRect.setSize({20, 20});*/

    //TODO: Hitbox fertig einrichten. Neues Rectangle als Feind gegenstand. Playersprite Leben geben.
    hitbox1.setFillColor(sf::Color::Green);
    hitbox1.setSize({96, 125});
    hitbox1.setPosition(playerSprite.getPosition()); //PRO
    //show hitbox on window



}
Sprite Player::getSprite() {
    return playerSprite;
}

bool Player::moveLeft() {
    return Leftpressed = true;
}

bool Player::moveRight() {
    return Rightpressed = true;
}

bool Player::jump() {
    return Uppressed = true;
}

bool Player::stopLeft() {
    return Leftpressed = false;
}

bool Player::stopRight() {
    return Rightpressed = false;
}

bool Player::stopJump() {

    return Uppressed = false;
}


void Player::update(float elapsedTime) { //TODO: Erinnerung CollisionDetection Dynamisch machen

    if (Leftpressed) {
        if (Leftpressed && Uppressed) {
            for (int i = 2; i < 3; ++i)
            playerSprite.move(-speed * elapsedTime*i*1.25, -speed*i * elapsedTime);
        }
        else
            for (int i = 2; i < 3; ++i)
                playerSprite.move(-speed * elapsedTime*i*1.25, 0);
    }

    if (Rightpressed) {
        if (Rightpressed && Uppressed) {
            for (int i = 2; i < 3; ++i)
                playerSprite.move(speed * elapsedTime*i*1.25, -speed*i * elapsedTime);
        }
        else
            for (int i = 2; i < 3; ++i)
                playerSprite.move(speed * elapsedTime*i*1.25, 0);
    }

    if (Uppressed) {
        for (int i = 2; i < 3; ++i)
            playerSprite.move(0, -speed* elapsedTime*i*2.25);
    }

    playerSprite.move(position);
    hitbox1.setPosition(playerSprite.getPosition());
    collisionDetection();
}


void Player::setPosX(float x) {
    position.x = x;
}

void Player::setPosY(float y) {
    //playerSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y);
    position.y = y;
}

void Player::setPos(float x, float y) {
    position.x = x;
    position.y = y;
}

float Player::getPosX() {
    return playerSprite.getPosition().x;
}

float Player::getPosY() {
    return playerSprite.getPosition().y;
}

Vector2f Player::getPos() {
    return position;
}

void Player::setVelX(float x) {
    velocity.x = x;
}

void Player::setVelY(float y) {
    velocity.y = y;
}

void Player::setVel(float x, float y) {
    velocity.x = x;
    velocity.y = y;
}

float Player::getVelX() {
    return velocity.x;
}

float Player::getVelY() {
    return velocity.y;
}

Vector2f Player::getVel() {
    return velocity;
}

void Player::collisionDetection() {

     //TODO: Border noch fixxen
    if (getPosY() >= 800) playerSprite.setPosition(playerSprite.getPosition().x, 800);
    if (getPosY() <= -21) playerSprite.setPosition(playerSprite.getPosition().x, -21);

    if (getPosX() >= 1772) playerSprite.setPosition(1772, playerSprite.getPosition().y);
    if (getPosX() <= -49) playerSprite.setPosition(-49, playerSprite.getPosition().y);

    /*if (getPosY() >= engine.getWindowHeight()-1955) playerSprite.setPosition(playerSprite.getPosition().x, engine.getWindowHeight()-1955);
    if (getPosY() <= engine.getWindowHeight()-1920) playerSprite.setPosition(playerSprite.getPosition().x, engine.getWindowHeight()-1920);

    if (getPosX() >= engine.getWindowWidght()-80) playerSprite.setPosition(engine.getWindowWidght()-30, playerSprite.getPosition().y);
    if (getPosX() <= engine.getWindowWidght()-1990) playerSprite.setPosition(engine.getWindowWidght()-1990, playerSprite.getPosition().y);*/

    /*if (getPosY() >= testRect.getPosition().y-100 *//*&& getPosY() <= testRect.getPosition().y-20*//*) playerSprite.setPosition(playerSprite.getPosition().x, testRect.getPosition().y-100);
    if(getPosY() == getPosY()) std::cout << testRect.getPosition().y << " \n";
    if(getPosY() == getPosY()) std::cout << getPosY() << " \nr";*/
}

bool Player::JumpPossibleGroundDetectorUltra() {
    if(getPosY() >= 800) return false;
    else return true;

}


