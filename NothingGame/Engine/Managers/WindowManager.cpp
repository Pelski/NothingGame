//
//  WindowManager.cpp
//  NothingGame
//
//  Created by Mateusz Pelka on 27.02.2017.
//  Copyright © 2017 Pelski. All rights reserved.
//

#include "WindowManager.hpp"

WindowManager::WindowManager() {
    SCREEN_W = 1920;
    SCREEN_H = 1080;
    
    // Creating window
    renderWindow.create(VideoMode(SCREEN_W, SCREEN_H, 32), "NothingGame");
    renderWindow.setFramerateLimit(240);
    
    // Loading icon
    Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    renderWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    gameState = MAIN_MENU;
}

void WindowManager::displayLoop() {
    while (renderWindow.isOpen()) {
        
        // Event handling
        while (renderWindow.pollEvent(eventManager.event)) {
            int eventCode = eventManager.handleEvent();
            
            if (eventCode == EventManager::EventHandle::WINDOW_CLOSE) {
                renderWindow.close();
            }
        }
        
        // Rendering
        renderWindow.clear(Color::Color(38, 187, 237));
        switch (gameState) {
            case SPLASH_SCREEN:
                // coś
                break;
            case MAIN_MENU:
                
                break;
                
            default:
                break;
        }
        renderWindow.display();
    }
}
