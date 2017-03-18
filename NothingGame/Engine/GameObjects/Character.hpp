//
//  Character.hpp
//  NothingGame
//
//  Created by Mateusz Pelka on 06.03.2017.
//  Copyright © 2017 Pelski. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <string.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Character {
public:
    Vector2f getPosition();
    void setPosition(Vector2f);

    void addVector(Vector2f);
    void jump();
    void moveLeft();
    void moveRight();
    
    Vector2f getSize();
    void setSize(Vector2f);
    
    string getTexture();

    void create(string, int, int, int, int, int, Vector2f, Vector2f, string);
    void update(float deltaTime);
    void draw(RenderTarget *target);
private:
    string name;
    int experience;
    int life;
    int starvation;
    int thirst;
    int lifeEnergy;
    float speed;
    float maxSpeed;
    
    Vector2f position;
    Vector2f size;
    Vector2f movementVector;
    string characterTexture;
};

#endif /* Character_hpp */
