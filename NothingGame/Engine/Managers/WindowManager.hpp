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
#include "../Scenes/TestScene.hpp"
#include "ImageManager.hpp"

using namespace std;
using namespace sf;

class WindowManager {
public:
    // Game states
    enum GameState {
        SPLASH_SCREEN,
        MAIN_MENU,
        TEST_SCENE,
        SETTINGS_MENU,
        CREDITS_MENU,
        LOADING_SCREEN,
        GAME_SCREEN,
        EXIT_STATE
    };
    RenderWindow renderWindow;
    RenderTexture renderTexture;

    WindowManager();
    void displayLoop();
private:
    int SCREEN_W;
    int SCREEN_H;

    ContextSettings settings;
    Image icon;
    Font mainFont;

    Vector2u getScreenSize();

    Clock deltaTime;

    EventManager eventManager;
    GameState gameState;
    ImageManager imageManager;

    SplashScreen splashScreen;
    TestScene testScene;

    bool boolFPSCounter;
};

#endif /* WindowManager_hpp */
