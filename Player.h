#ifndef MARIO_PLAYER_H
#define MARIO_PLAYER_H
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Player {
private:
    Vector2f position;
    Vector2f velocity;
    Vector2f hitbox_width;
    Vector2f hitbox_height;
    Vector2f size; // Width and Height

    bool Leftpressed;
    bool Rightpressed;
    bool Uppressed;
    bool isTurningLeft;
    bool isTurningRight;
    float speed;

    Texture playerTexture;
    Sprite playerSprite;


public:
    Player();

    Sprite getSprite();

    RectangleShape hitbox1;
    RectangleShape hitbox2;
    RectangleShape liferect;
    RectangleShape testRect;

    bool moveRight();

    bool moveLeft();

    bool jump();

    bool stopLeft();

    bool stopRight();

    bool stopJump();

    void update(float elapsedTime);

    void collisionDetection();

    bool JumpPossibleGroundDetectorUltra();

    void setIsTurning(bool isTurning);

    void setPosX(float x);

    void setPosY(float y);

    void setPos(float x, float y);

    float getPosX();

    float getPosY();

    float lifepointsP1;

    Vector2f getPos();

    void setVelX(float x);

    void setVelY(float y);

    void setVel(float x, float y);

    float getVelX();

    float getVelY();

    Vector2f getVel();

};

#endif //MARIO_PLAYER_H