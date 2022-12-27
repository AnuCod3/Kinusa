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
    bool Leftpressed;
    bool Rightpressed;
    bool Uppressed;
    float speed;
    Texture playerTexture;
    Sprite playerSprite;

public:
    Player();
    Sprite getSprite();

        bool getIsJump();
        bool moveRight();
         bool moveLeft();
        bool jump();
        bool stopLeft();
        bool stopRight();
        bool stopJump();
        void update(float elapsedTime);
        void collisionDetection();
       bool JumpPossibleGroundDetec();

       void setPosX(float x);
       void setPosY(float y);
       void setPos(float x, float y);

       /*Sprite getSprite();*/
       float getPosX();
       float getPosY();
       Vector2f getPos();

    void setVelX(float x);
    void setVelY(float y);
    void setVel(float x, float y);

    float getVelX();
    float getVelY();
    Vector2f getVel();

};
#endif //MARIO_PLAYER_H