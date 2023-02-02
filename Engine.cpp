//
// Created by anush on 27.12.2022.
//
#include <iostream>
#include <chrono>
#include <thread>
#include "Engine.h"
#include "Player.h"
#include "Menu.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;
const float GRAVITY = 50;
using namespace std;
Player Player;
Menu Menu;
RenderWindow gameWindow;

Engine::Engine() {
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    gameWindow.create(VideoMode(WIDTH, HEIGHT), "Kinusa"); //XXXXXXXXXXXXXXX

    gameWindow.setFramerateLimit(60);
    bgTexture.loadFromFile("../background.png");
    bgSprite.setTexture(bgTexture);
    bgSprite.setScale(1 , 0.75);
    bgSprite.setTexture(bgTexture);
    isJump = false;
}

void Engine::start() {
    Clock clock;
    while (gameWindow.isOpen()) {
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        input();
        update(dtAsSeconds);
        draw();

    }
}

void Engine::input() {
    Clock Jumptimer;
    Event event;

    while (gameWindow.pollEvent(event)) {

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            gameWindow.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            Player.moveLeft();
        } else {
            Player.stopLeft();
        }
        if (Keyboard::isKeyPressed(Keyboard::D)){
            Player.moveRight();
        } else {
            Player.stopRight();
        }
        if (Keyboard::isKeyPressed(Keyboard::Space) && !isJump) {
            isJump = true;
            Player.jump();
        } else {
            Player.stopJump();
        }
        setIsJump(Player.JumpPossibleGroundDetectorUltra());
    }
}

void Engine::update(float dtAsSeconds) {
    Player.update(dtAsSeconds);
    Player.collisionDetection();
    Player.setPosY((GRAVITY+120) * dtAsSeconds);

    /*Player.setPosY((GRAVITY+120) * -dtAsSeconds);*/
    // cout << Player.getPosY() << "\n";
}

void Engine::draw() {
    gameWindow.clear(Color::White);
    gameWindow.draw(bgSprite);
    gameWindow.draw(Player.getSprite());
    //gameWindow.draw(Player.hitbox1);
    gameWindow.draw(Player.testRect);
    gameWindow.display();

}

void Engine::setIsJump(bool val) {
    isJump = val;
}




