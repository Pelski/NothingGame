//
//  TestScene.hpp
//  NothingGame
//
//  Created by Mateusz Pelka on 06.03.2017.
//  Copyright © 2017 Pelski. All rights reserved.
//

#ifndef TestScene_hpp
#define TestScene_hpp

#include <iostream>
#include <cstring>
#include "SFML/Graphics.hpp"
#include "../../ResourcePath.hpp"
#include "../GameObjects/Character.hpp"
#include "../Managers/ImageManager.hpp"

using namespace std;
using namespace sf;

class TestScene {
public:
    TestScene();
    bool create(RenderTarget *target, ImageManager *imageManager);
    void update(float deltaTime);
    void draw(RenderTarget *target);

    bool isInitialized();
    bool isFinished();
    void setGameLogoPosition(Vector2f position);

private:
    bool initialized;
    Sprite gameLogo;
    ImageManager *imageManager;

    Character character;
};

#endif /* TestScene_hpp */
