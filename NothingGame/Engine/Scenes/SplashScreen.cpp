//
// Created by Mateusz Pelka on 07.03.2017.
//

#include <iostream>
#include "SplashScreen.hpp"
#include "../../ResourcePath.hpp"

SplashScreen::SplashScreen() {
    initialized = false;
}

bool SplashScreen::isInitialized() {
    return initialized;
}

bool SplashScreen::create(RenderTarget *target) {
    if (!gameLogoTexture.loadFromFile(resourcePath() + "Caution.png")) {
        cout << "Can't load Caution.png file!" << endl;
        return false;
    }

    gameLogo.setTexture(gameLogoTexture);

    Vector2u screenSize = target->getSize();
    gameLogo.setPosition(screenSize.x / 2 - gameLogoTexture.getSize().x / 2, screenSize.y / 2 - gameLogoTexture.getSize().y / 2);
    animateStep = 0;
    gameLogo.setColor(Color::Color(255, 255, 255, animateStep));

    initialized = true;
    return true;
}

void SplashScreen::update(float deltaTime) {
    if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
        gameLogo.setPosition(gameLogo.getPosition().x + deltaTime * 80, gameLogo.getPosition().y);
    }

    if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
        gameLogo.setPosition(gameLogo.getPosition().x - deltaTime * 80, gameLogo.getPosition().y);
    }

    if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
        gameLogo.setPosition(gameLogo.getPosition().x, gameLogo.getPosition().y - deltaTime * 80);
    }

    if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
        gameLogo.setPosition(gameLogo.getPosition().x, gameLogo.getPosition().y + deltaTime * 80);
    }

    if (int(animateStep) < 255) {
        gameLogo.setColor(Color::Color(255, 255, 255, int(animateStep)));
        gameLogo.setPosition(gameLogo.getPosition().x, gameLogo.getPosition().y - deltaTime * (255 - int(animateStep)));
        animateStep += 100 * deltaTime;
    }
}

void SplashScreen::draw(RenderTarget *target) {
    target->draw(gameLogo);
}

bool SplashScreen::isFinished() {
    if (int(animateStep) >= 255) {
        return true;
    } else {
        return false;
    }
}

Vector2f SplashScreen::getLogoPosition() {
    return gameLogo.getPosition();
}