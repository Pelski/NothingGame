//
// Created by Mateusz Pelka on 07.03.2017.
//

#ifndef NOTHINGGAME_SPLASHSCREEN_H
#define NOTHINGGAME_SPLASHSCREEN_H

#include <cstring>
#include "SFML/Graphics.hpp"
#include "../Managers/ImageManager.hpp"

using namespace std;
using namespace sf;

class SplashScreen {
public:
    SplashScreen();

    bool create(RenderTarget *target, ImageManager *imageManager);
    void update(float deltaTime);
    void draw(RenderTarget *target);

    bool isInitialized();
    bool isFinished();
    Vector2f getLogoPosition();

private:
    bool initialized;
    float animateStep;
    Sprite gameLogo;

    ImageManager *imageManager;
};


#endif //NOTHINGGAME_SPLASHSCREEN_H
