//
// Created by Kilian on 24.12.2022.
//

#include "Player.h"
using namespace std;

Player::Player(){
    velocity = {0.0f, 0.0f};
    movementSpeed = 10;
    //gravity = 9.81f; // Schwerkraft
    //jumpVelocity = 10.0f; // Sprunggeschwindigkeit
    maxJumpDuration = 0.5f; // Maximale Dauer des Sprungs
    jumpDuration = 0.0f; // Dauer des aktuellen Sprungs
    isJumping = false; // Gibt an, ob sich der Spieler im Sprung befindet
    x = -25;
    y = 500;
    texture.loadFromFile("C:\\Users\\anush\\CLionProjects\\Marioi\\Wraith_03_Idle_000.png");
    sprite.setTexture(texture);
    sprite.setOrigin(25, 25);
    sprite.setScale(0.25, 0.25);
    sprite.setPosition(x, y);
}

float Player::getPositionX() {
    return sprite.getPosition().x;
}

float Player::getPositionY() {
    return sprite.getPosition().y; // Geht das mit Sprite x und y Koords oder direkt x und y Variabel-Koords von Player Class verwenden?
}

void Player::setPosition(float x, float y_Koordinate) {
    y = y_Koordinate;
    sprite.setPosition(x, y);

}

/*void Player::setPositionY(float yK) {
    y = yK;

}*/

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

void Player::update(Player& player, float dt) {
    // Aktualisiere die Sprungdauer
    if (player.isJumping)
        player.jumpDuration += dt;

    // Beende den Sprung, wenn die maximale Dauer erreicht wurde
    if (player.jumpDuration > maxJumpDuration)
        player.isJumping = false;

    // Berechne die vertikale Geschwindigkeit entsprechend der Schwerkraft und der Sprungdauer
   // player.velocity.y = jumpVelocity - gravity * player.jumpDuration;//

    // Aktualisiere die Position des Spielers entsprechend seiner Geschwindigkeit
    player.x += player.velocity.x * dt;
    player.y += player.velocity.y * dt;
}

void Player::jump(Player &player) {
// Starte den Sprung, wenn der Spieler sich nicht bereits im Sprung befindet
    if (!player.isJumping)
    {
        player.isJumping = true;
        player.jumpDuration = 0.0f;
    }
}




