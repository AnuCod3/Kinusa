#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Engine.h"
using namespace std;
Engine engine;
Player::Player(){
    speed = 100;
    playerTexture.loadFromFile("../PlayerTexture.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(250, 250);
    //playerSprite.setScale(209, 209);
    velocity.x = 8;
    velocity.y = 8;
    Leftpressed = false;
    Rightpressed = false;
    Uppressed = false;
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


void Player::update(float elapsedTime) {

    if (Leftpressed) {
        if (Leftpressed && Uppressed) {
            for (int i = 2; i < 7; ++i)
            playerSprite.move(-speed * elapsedTime*i*1.5, -speed*i * elapsedTime);
            //playerSprite.move(speed * elapsedTime*35, -speed*35 * elapsedTime); // Diese Methode ist eher Teleportieren als Springen, Mit Kilian diskutieren
        }
        else
            for (int i = 2; i < 3; ++i)
                playerSprite.move(-speed * elapsedTime*i*1.5, 0);
        /*playerSprite.move(-speed * elapsedTime*1.5, 0);*/                       // Gleiches wie oben
    }

    if (Rightpressed) {
        if (Rightpressed && Uppressed) {
            for (int i = 2; i < 7; ++i)
                playerSprite.move(speed * elapsedTime*i*1.5, -speed*i * elapsedTime);
            //playerSprite.move(speed * elapsedTime*35, -speed*35 * elapsedTime); // Diese Methode ist eher Teleportieren als Springen, Mit Kilian diskutieren
        }
        else
            for (int i = 2; i < 3; ++i)
                playerSprite.move(speed * elapsedTime*i*1.5, 0);
        /*playerSprite.move(speed * elapsedTime*1.5, 0);*/                        // Gleiches wie oben
    }

    if (Uppressed) {
        for (int i = 2; i < 7; ++i)
            playerSprite.move(0, -speed* elapsedTime*i*2.5);
    }

    playerSprite.move(position);
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
    if (getPosY() > 250) playerSprite.setPosition(playerSprite.getPosition().x, 250);
    if (getPosY() <= -25) playerSprite.setPosition(playerSprite.getPosition().x, -25);

    if (getPosX() >= 668) playerSprite.setPosition(668, playerSprite.getPosition().y);
    if (getPosX() <= -140) playerSprite.setPosition(-140, playerSprite.getPosition().y);

}

bool Player::JumpPossibleGroundDetec() {
    if(getPosY() >= 250) return false;
    else return true;

}


