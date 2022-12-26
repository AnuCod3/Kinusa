#ifndef MARIO_PLAYER_H
#define MARIO_PLAYER_H
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

class Player {
private:
    Texture texture;
    Sprite sprite;

    bool isJump;

    Vector2f position;
    Vector2f velocity;
public:
    Player();

    bool getIsJump();
   /* void moveRight();
    void moveLeft();
    void jump();

    void setPosX(float x);
    void setPosY(float y);
    void setPos(float x, float y);

    Sprite getSprite();
    float getPosX();
    float getPosY();
    Vector2f getPos();

    void setVelX(float x);
    void setVelY(float y);
    void setVel(float x, float y);

    float getVelX();
    float getVelY();
    Vector2f getVel();
*/
    void setIsJump(bool isJump);
};
#endif //MARIO_PLAYER_H