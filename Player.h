//
// Created by Kilian on 24.12.2022.
//

#ifndef MARIO_PLAYER_H
#define MARIO_PLAYER_H
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Player {
private:
    Texture texture;
    Sprite sprite;

    float x, y;
    float movementSpeed;
    float jumpHeight;
    float velocityX, velocityY;
    float gravity;
    float time;

public:
    Player();
    Sprite getSprite();
    void moveLeft(); // Move Player in a specific direction
    void moveRight();
    void moveUp();
    void moveDown();

    void stopLeft();// Stop Player moving in a specific direction
    void stopRight();
    void stopUp();

    double getPositionX();
    double getPositionY();
    void setPosition(float x, float y);



};

#endif //MARIO_PLAYER_H
