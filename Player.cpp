#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Engine.h"

using namespace std;
Engine engine;

//TODO: Neuer Char mit Spritesheet und Animationen (Idle,Laufen,Sprung,Angriff)
Player::Player() {
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
    isTurningLeft = false;
    isTurningRight = true; //rechts muss auf true gesetzt werden, damit der Spieler beim start nicht direkt nach links buggt
    lifepointsP1 = 100;

    hitbox1.setFillColor(sf::Color::Green);
    hitbox1.setSize({96, 125});
    hitbox1.setPosition(playerSprite.getPosition());

    testRect.setFillColor(sf::Color::Red);
    testRect.setSize({96, 125});
    testRect.setPosition(1000, 800);

    liferect.setFillColor(sf::Color::Green);
    liferect.setSize({lifepointsP1 * 2, 30});
    liferect.setPosition(100, 100);
}

Sprite Player::getSprite() {
    return playerSprite;
}

bool Player::moveLeft() {
    if (!isTurningLeft) {
        playerSprite.setPosition(playerSprite.getPosition().x + 70, playerSprite.getPosition().y);
        isTurningLeft = true;
        isTurningRight = false;
    }
    playerSprite.setScale(-0.45, 0.45); //Sprite spiegeln
    return Leftpressed = true;
}

bool Player::moveRight() {
    if (!isTurningRight) {
        playerSprite.setPosition(playerSprite.getPosition().x - 70, playerSprite.getPosition().y);
        isTurningRight = true;
        isTurningLeft = false;
    }
    playerSprite.setScale(0.45, 0.45);
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

//TODO: CollisionDetection Dynamisch machen
void Player::update(float elapsedTime) {

    if (Leftpressed) {
        if (Leftpressed && Uppressed) {
            for (int i = 2; i < 3; ++i)
                playerSprite.move(-speed * elapsedTime * i * 1.25, -speed * i * elapsedTime);
        } else
            for (int i = 2; i < 3; ++i)
                playerSprite.move(-speed * elapsedTime * i * 1.25, 0);
    }

    if (Rightpressed) {
        if (Rightpressed && Uppressed) {
            for (int i = 2; i < 3; ++i)
                playerSprite.move(speed * elapsedTime * i * 1.25, -speed * i * elapsedTime);
        } else
            for (int i = 2; i < 3; ++i)
                playerSprite.move(speed * elapsedTime * i * 1.25, 0);
    }

    if (Uppressed) {
        for (int i = 2; i < 3; ++i)
            playerSprite.move(0, -speed * elapsedTime * i * 2.25);
    }

    playerSprite.move(position);
    hitbox1.setPosition(playerSprite.getPosition());
    collisionDetection();
}


void Player::setPosX(float x) {
    position.x = x;
}

void Player::setPosY(float y) {
    position.y = y;
}

float Player::getPosX() {
    return playerSprite.getPosition().x;
}

float Player::getPosY() {
    return playerSprite.getPosition().y;
}


void Player::collisionDetection() {

    //TODO: Border noch fixxen
    if (getPosY() >= 753) playerSprite.setPosition(playerSprite.getPosition().x, 753);
    if (getPosY() <= -21) playerSprite.setPosition(playerSprite.getPosition().x, -21);

    if (getPosX() >= 1772) playerSprite.setPosition(1772, playerSprite.getPosition().y);
    if (getPosX() <= -49) playerSprite.setPosition(-49, playerSprite.getPosition().y);


    //Damagedetection
    bool hasTakenDamage = false;
    if (hitbox1.getGlobalBounds().intersects(testRect.getGlobalBounds())) {
        hasTakenDamage = true;
        lifepointsP1 -= 10;
        liferect.setSize({lifepointsP1 * 2, 30});
        if (isTurningLeft) {
            playerSprite.setPosition(playerSprite.getPosition().x + 50, playerSprite.getPosition().y);
        } else if (isTurningRight) {
            playerSprite.setPosition(playerSprite.getPosition().x - 50, playerSprite.getPosition().y);
        }
    }

    if (!hasTakenDamage) playerSprite.setColor(sf::Color::White);
    else playerSprite.setColor(sf::Color::Red);

    //Respawn
    //TODO: Player blinken lassen wenn er respawned
    if (lifepointsP1 <= 0) {
        playerSprite.setPosition(0, 800);
        lifepointsP1 = 100;
        liferect.setSize({lifepointsP1 * 2, 30});

    }
}

bool Player::JumpPossibleGroundDetectorUltra() {
    if (getPosY() >= 753) return false;
    else return true;

}

void Player::setIsTurning(bool val) {
    isTurningLeft = val;
    isTurningRight = val;
}



