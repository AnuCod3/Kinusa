//
// Created by anush on 27.12.2022.
//
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

//TODO: Einstellungen einbauen für die Auflösung und die FPS Anzeige und die FPS selbst, Vollbildmodus, Sound, Musik, Tastaturbelegung, etc.
//TODO: Einstellungen speichern und laden
//TODO: Getter uns Setter ENDLICH richtig einbauen und ordnen

Engine::Engine() {
    Vector2f resolution;
    Vector2f resize;
    resize.x = 1920;
    resize.y = 1080;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    gameWindow.create(VideoMode(WIDTH, HEIGHT), "Kinusa");
    gameWindow.setFramerateLimit(60);
    bgTexture.loadFromFile("../NewLevel.png");
    bgSprite.setTexture(bgTexture);
    bgSprite.setScale(1, 0.75);
    bgSprite.setScale(
            resize.x / bgTexture.getSize().x,
            resize.y / bgTexture.getSize().y
    );
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
    Event event{};
//TODO: Steuerung deaktivieren und aktivieren lassen (z.B deaktivieren für paar sek nach respawn)
    while (gameWindow.pollEvent(event)) {

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            gameWindow.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            Player.moveLeft();
        } else {
            Player.stopLeft();
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
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
    Player.setPosY((GRAVITY + 120) * dtAsSeconds);
}

void Engine::draw() {
    gameWindow.clear(Color::White);
    gameWindow.draw(bgSprite);
    gameWindow.draw(Player.getSprite());
    gameWindow.draw(Player.testRect);
    gameWindow.draw(Player.liferect);

    gameWindow.display();
}

void Engine::setIsJump(bool val) {
    isJump = val;
}






