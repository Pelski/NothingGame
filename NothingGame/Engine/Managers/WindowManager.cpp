//
//  WindowManager.cpp
//  NothingGame
//
//  Created by Mateusz Pelka on 27.02.2017.
//  Copyright © 2017 Pelski. All rights reserved.
//

#include <iostream>
#include "WindowManager.hpp"
#include "../../ResourcePath.hpp"

WindowManager::WindowManager() {
    SCREEN_W = 1920;
    SCREEN_H = 1080;

    settings.antialiasingLevel = 0;
    settings.sRgbCapable = false;

    // Creating window
    renderWindow.create(VideoMode(SCREEN_W, SCREEN_H, 32), "Caution!", Style::Close | Style::Titlebar, settings);
    renderWindow.setFramerateLimit(250);
    renderWindow.setVerticalSyncEnabled(true);

    // Creating main render texture

    // TODO: RenderTexture must work, it's realy important! But you can do it with Views if you handle it.
    renderTexture.create(SCREEN_W, SCREEN_H);
    renderTexture.setActive(true);
    renderTexture.setSmooth(true);

    // Loading icon
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return;
    }
    renderWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    if (!mainFont.loadFromFile(resourcePath() + "BebasNeue.otf")) {
        return;
    }

    gameState = SPLASH_SCREEN;

    // FPS counter
    boolFPSCounter = true;
    deltaTime.restart();
}

void WindowManager::displayLoop() {
    float deltaTimeFloat = 0;
    while (renderWindow.isOpen()) {
        // Event handling
        while (renderWindow.pollEvent(eventManager.event)) {
            int eventCode = eventManager.handleEvent();
            
            if (eventCode == EventManager::EventHandle::WINDOW_CLOSE) {
                renderWindow.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::LBracket)) {
            boolFPSCounter = true;
        }

        if (Keyboard::isKeyPressed(Keyboard::RBracket)) {
            boolFPSCounter = false;
        }

        switch (gameState) {
            case SPLASH_SCREEN:
                if (!splashScreen.isInitialized()) {
                    if (!splashScreen.create(&renderWindow, &imageManager)) {
                        return;
                    }
                }
                // Clearing render window
                renderWindow.clear(Color::Color(47, 47, 47));

                if (splashScreen.isFinished()) {
                    gameState = TEST_SCENE;
                } else {
                    splashScreen.update(deltaTimeFloat);
                    splashScreen.draw(&renderWindow);
                }
                break;

            case TEST_SCENE:
                if (!testScene.isInitialized()) {
                    if (!testScene.create(&renderWindow, &imageManager)) {
                        return;
                    }
                    testScene.setGameLogoPosition(splashScreen.getLogoPosition());
                    // Temp!
                    // testScene.setGameLogoPosition(Vector2f(100.0f, 50.0f));
                }

                // Clearing render window
                renderWindow.clear(Color::Color(0, 184, 245));

                if (testScene.isFinished()) {
                    //testScene = NULL;
                    gameState = EXIT_STATE;
                } else {
                    testScene.update(deltaTimeFloat);
                    testScene.draw(&renderWindow);
                }
                break;

            case MAIN_MENU:

                break;

            case GAME_SCREEN:
                break;

            default:
                break;
        }

        /***
         * FPS COUNTER
         */
        float fps = 1.f / deltaTimeFloat;
        char c[6];
        sprintf(c, "FPS: %d", int(fps));
        string string(c);
        String str(string);
        Text text;
        text.setFont(mainFont);
        text.setPosition(10, 10);
        text.setFillColor(Color::Red);
        text.setString(str);

        //renderTexture.display();

        // Clearing render window
        // renderWindow.clear();

        // Drawing main render texture to render window
        const Texture& _renderTexture = renderTexture.getTexture();
        Sprite renderSprite;
        renderSprite.setPosition(0, 0);
        renderSprite.setTexture(_renderTexture);
        //renderWindow.draw(renderSprite);

        // Displaying FPS counter
        if (boolFPSCounter) {
            renderWindow.draw(text);
        }

        renderWindow.display();
        deltaTimeFloat = deltaTime.restart().asSeconds();
    }
}

Vector2u WindowManager::getScreenSize() {
    return Vector2u(SCREEN_W, SCREEN_H);
}