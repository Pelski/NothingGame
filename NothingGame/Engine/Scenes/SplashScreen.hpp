//
// Created by Mateusz Pelka on 07.03.2017.
//

#ifndef NOTHINGGAME_SPLASHSCREEN_H
#define NOTHINGGAME_SPLASHSCREEN_H

#include <string.h>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class SplashScreen {
public:
    bool create(RenderWindow &target);
    void update(float deltaTime);
    void draw();

private:
    Sprite gameLogo;
    Texture gameLogoTexture;

    RenderWindow* renderTarget;
};


#endif //NOTHINGGAME_SPLASHSCREEN_H
