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
    Vector2f velocity;
    float movementSpeed;
    float jumpHeight;
    //float gravity; // Schwerkraft
    //float jumpVelocity; // Sprunggeschwindigkeit
    float maxJumpDuration; // Maximale Dauer des Sprungs
    float jumpDuration; // Dauer des aktuellen Sprungs
    bool isJumping; // Gibt an, ob sich der Spieler im Sprung befindet

public:
    Player();
    Sprite getSprite();
    void moveLeft(); // Move Player in a specific direction
    void moveRight();
    void moveUp();
    void moveDown();
    void jump(Player& player);

    void stopLeft();// Stop Player moving in a specific direction
    void stopRight();
    void stopUp();

    void update(Player& player, float dt);

    float getPositionX();
    float getPositionY();
    void setPosition(float x, float y);
    void setPositionY(float y);



};

#endif //MARIO_PLAYER_H
