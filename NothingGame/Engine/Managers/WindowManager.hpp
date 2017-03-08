//
//  WindowManager.hpp
//  NothingGame
//
//  Created by Mateusz Pelka on 27.02.2017.
//  Copyright © 2017 Pelski. All rights reserved.
//

#ifndef WindowManager_hpp
#define WindowManager_hpp

#include <stdio.h>
#include <list>
#include <SFML/Graphics.hpp>

#include "EventManager.hpp"
#include "../Scenes/SplashScreen.hpp"

using namespace std;
using namespace sf;

class WindowManager {
public:
    // Game states
    enum GameState {
        SPLASH_SCREEN,
        MAIN_MENU,
        SETTINGS_MENU,
        CREDITS_MENU,
        LOADING_SCREEN,
        GAME_SCREEN,
        EXIT_STATE
    };
    // Vars
    RenderWindow renderWindow;
    
    // Methods
    WindowManager();
    void displayLoop();
private:
    // Vars
    int SCREEN_W;
    int SCREEN_H;

    ContextSettings settings;
    Image icon;
    Font mainFont;

    Vector2u getScreenSize();

    Clock deltaTime;

    EventManager eventManager;
    GameState gameState;

    SplashScreen splashScreen;
    // Methods
};

#endif /* WindowManager_hpp */
