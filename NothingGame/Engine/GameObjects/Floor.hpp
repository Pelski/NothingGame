//
// Created by Mateusz Pelka on 27.03.2017.
//

#ifndef NOTHINGGAME_FLOOR_H
#define NOTHINGGAME_FLOOR_H

#include <stdio.h>
#include <string.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Floor {
public:
    Vector2f getPosition();
    void setPosition(Vector2f);

    Vector2f getSize();
    void setSize(Vector2f);

    string getTexture();

    void create(string, Vector2f, Vector2f, Vector2f);
    void update(float deltaTime);
    void draw(RenderTarget *target);

private:
    string textureName;
    Vector2f position;
    Vector2f size;
    Vector2f movementVector;
};


#endif //NOTHINGGAME_FLOOR_H
