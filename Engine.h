//
// Created by Kilian on 26.12.2022.
//
#include <SFML/Graphics.hpp>
#include "Player.h"

#ifndef MARIO_ENGINE_H
#define MARIO_ENGINE_H
using namespace sf;

class Engine {
private:
    Sprite bgSprite;
    Texture bgTexture;
    Texture playerTexture;
    Sprite playerSprite;
    Player playerone;
    bool isJump;

    void input();

    void update(float dtAsSeconds);

    void draw();

public:
    Engine();

    void start();

    void setIsJump(bool isJump);

};


#endif //MARIO_ENGINE_H
