#include "Player.h"
using namespace std;

Player::Player(){
    isJump = false;
    Texture playeroneTexture;
    playeroneTexture.loadFromFile("C:\\Users\\anush\\CLionProjects\\Marioi\\Wraith_03_Idle_000.png");

    Sprite playeroneSprite;
    playeroneSprite.setTexture(playeroneTexture);
    playeroneSprite.setPosition(0, 0);
    playeroneSprite.setScale(0.5, 0.5);
}

bool Player::getIsJump() {
    return isJump;
}

void Player::setIsJump(bool isJump) {
    Player::isJump = isJump;
}


/*void Player::moveRight() {
    position.x += velocity.x;
    sprite.setPosition(position.x , getPosY());
}

void Player::moveLeft() {
    position.x -= velocity.x;
    sprite.setPosition(position.x, getPosY());
}

void Player::jump() {
    position.y -= velocity.y;
    sprite.setPosition(position.y, getPosX());
}

void Player::setPosX(float x) {
    position.x = x;
}

void Player::setPosY(float y) {
    position.y = y;
}

void Player::setPos(float x, float y) {
    position.x = x;
    position.y = y;
}

Sprite Player::getSprite() {
    return Sprite();
}

float Player::getPosX() {
    return position.x;
}

float Player::getPosY() {
    return position.y;
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
*/