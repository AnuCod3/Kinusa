//
// Created by Kilian on 24.12.2022.
//

#include "Player.h"
using namespace std;

Player::Player(){
    movementSpeed = 10;
    velocityX = movementSpeed; // Bro frag nicht
    velocityY = movementSpeed; // Bro frag nicht
    jumpHeight = 12.5; // Bro frag nicht
    gravity = 0.5f; // Bro frag nicht
    time = 2.5; // Bro frag nicht
    x = -25;
    y = 500;
    texture.loadFromFile("C:\\Users\\anush\\CLionProjects\\Marioi\\Wraith_03_Idle_000.png");
    sprite.setTexture(texture);
    sprite.setOrigin(25, 25);
    sprite.setScale(0.25, 0.25);
    sprite.setPosition(x, y);
}

double Player::getPositionX() {
    return sprite.getPosition().x;
}

double Player::getPositionY() {
    return sprite.getPosition().y;
}

void Player::setPosition(float x, float y = -650) {
    sprite.setPosition(x, sprite.getPosition().y);
}

void Player::moveRight() {
    x += movementSpeed;
    sprite.setPosition(x, sprite.getPosition().y);
}

void Player::moveLeft() {
    x -= movementSpeed;
    sprite.setPosition(x, sprite.getPosition().y);
}

void Player::moveUp() {
    y -= jumpHeight;
    sprite.setPosition(x, y*1.55);
    sprite.setPosition(x, y*0.95);

    sprite.setPosition(x, y);
}

void Player::moveDown() {
    y += jumpHeight;
    sprite.setPosition(x, y);
}

Sprite Player::getSprite() {
    return sprite;
}


