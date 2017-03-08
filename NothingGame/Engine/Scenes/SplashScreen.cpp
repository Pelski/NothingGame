//
// Created by Mateusz Pelka on 07.03.2017.
//

#include "SplashScreen.hpp"
#include "../../ResourcePath.hpp"

bool SplashScreen::create(RenderWindow &target) {
    if (!gameLogoTexture.loadFromFile(resourcePath() + "Caution.png")) {
        return false;
    } else {
        gameLogo.setTexture(gameLogoTexture);
    }

    Vector2u screenSize = target.getSize();
    gameLogo.setPosition(screenSize.x / 2 - gameLogoTexture.getSize().x / 2, screenSize.y / 2 - gameLogoTexture.getSize().y / 2);

    renderTarget = &target;

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
}

void SplashScreen::draw() {
    renderTarget->draw(gameLogo);
}