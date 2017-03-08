//
//  WindowManager.cpp
//  NothingGame
//
//  Created by Mateusz Pelka on 27.02.2017.
//  Copyright © 2017 Pelski. All rights reserved.
//

#include "WindowManager.hpp"
#include "../../ResourcePath.hpp"

WindowManager::WindowManager() {
    SCREEN_W = 1920;
    SCREEN_H = 1080;

    settings.antialiasingLevel = 0;
    settings.sRgbCapable = false;

    // Creating window
    renderWindow.create(VideoMode(SCREEN_W, SCREEN_H, 32), "NothingGame", Style::Default, settings);
    renderWindow.setFramerateLimit(60);
    renderWindow.setVerticalSyncEnabled(true);
    
    // Loading icon
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return;
    }
    renderWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    if (!mainFont.loadFromFile(resourcePath() + "BebasNeue.otf")) {
        return;
    }

    gameState = SPLASH_SCREEN;
    if (!splashScreen.create(renderWindow)) {
        return;
    }

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

        switch (gameState) {
            case SPLASH_SCREEN:
                splashScreen.update(deltaTimeFloat);
                splashScreen.draw();
                break;
            case MAIN_MENU:
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
        renderWindow.draw(text);

        renderWindow.display();
        renderWindow.clear(Color::Color(38, 187, 237));
        deltaTimeFloat = deltaTime.restart().asSeconds();
    }
}

Vector2u WindowManager::getScreenSize() {
    return Vector2u(SCREEN_W, SCREEN_H);
}