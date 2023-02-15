//
// Created by anush on 03.01.2023.
//

#include "Menu.h"
#include "Engine.h"

//TODO: Menü komplett neu aufbauen (Buttons, Texte, etc.) und in die Engine einbauen

//Create Menu with Start and settings button
Menu::Menu() {
    //Create Background
    Texture bgTexture;
    bgTexture.loadFromFile("../NewLevel.png");
    Sprite bgSprite;
    bgSprite.setTexture(bgTexture);
    bgSprite.setScale(1, 0.75);
    bgSprite.setScale(
            1920 / bgTexture.getSize().x,
            1080 / bgTexture.getSize().y
    );
    bgSprite.setTexture(bgTexture);

    //Create Start Button
    Texture startTexture;
    startTexture.loadFromFile("../StartButton.png");
    Sprite startSprite;
    startSprite.setTexture(startTexture);
    startSprite.setScale(1, 0.75);
    startSprite.setScale(
            1920 / startTexture.getSize().x,
            1080 / startTexture.getSize().y
    );
    startSprite.setTexture(startTexture);
    startSprite.setPosition(1920 / 2 - startTexture.getSize().x / 2, 1080 / 2 - startTexture.getSize().y / 2);

    //Create Settings Button
    Texture settingsTexture;
    settingsTexture.loadFromFile("../SettingsButton.png");
    Sprite settingsSprite;
    settingsSprite.setTexture(settingsTexture);
    settingsSprite.setScale(1, 0.75);
    settingsSprite.setScale(
            1920 / settingsTexture.getSize().x,
            1080 / settingsTexture.getSize().y
    );
    settingsSprite.setTexture(settingsTexture);
    settingsSprite.setPosition(1920 / 2 - settingsTexture.getSize().x / 2, 1080 / 2 - settingsTexture.getSize().y / 2 + 100);

    //Create Exit Button
    Texture exitTexture;
    exitTexture.loadFromFile("../ExitButton.png");
    Sprite exitSprite;
    exitSprite.setTexture(exitTexture);
    exitSprite.setScale(1, 0.75);
    exitSprite.setScale(
            1920 / exitTexture.getSize().x,
            1080 / exitTexture.getSize().y
    );
    exitSprite.setTexture(exitTexture);
    exitSprite.setPosition(1920 / 2 - exitTexture.getSize().x / 2, 1080 / 2 - exitTexture.getSize().y / 2 + 200);

    //Create Text
    Font font;
    font.loadFromFile("../arial.ttf");
    Text text;
}
