//
//  TestScene.cpp
//  NothingGame
//
//  Created by Mateusz Pelka on 06.03.2017.
//  Copyright © 2017 Pelski. All rights reserved.
//

#include "TestScene.hpp"

TestScene::TestScene() {
    initialized = false;
}

bool TestScene::isInitialized() {
    return initialized;
}

bool TestScene::create(RenderTarget *target, ImageManager *imageManager) {
    this->imageManager = imageManager;
    imageManager->loadTexture("logo", "Caution.png");

    gameLogo.setTexture(imageManager->getRef("logo"));

    Vector2u screenSize = target->getSize();
    gameLogo.setPosition(screenSize.x / 2 - imageManager->getRef("logo").getSize().x / 2, screenSize.y / 2 - imageManager->getRef("logo").getSize().y / 2);
    gameLogo.setColor(Color::Color(255, 255, 255));

    character.create("Pelski", 0, 100, 100, 100, 100, Vector2f(150.0f, 300.0f), Vector2f(75.0f, 100.0f), "void");

    initialized = true;
    return true;
}

void TestScene::update(float deltaTime) {
    if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
        character.moveRight();
    }

    if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
        character.moveLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
        character.jump();
    } else {
        if (character.getVerticalSpeed() == 0.0f && (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))) {
            character.crouch();
        }
    }

    character.update(deltaTime);
}

void TestScene::draw(RenderTarget *target) {
    target->draw(gameLogo);

    character.draw(target);
}

bool TestScene::isFinished() {
    return false;
}

void TestScene::setGameLogoPosition(Vector2f position) {
    gameLogo.setPosition(position);
}