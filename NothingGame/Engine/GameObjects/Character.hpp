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
    // Methods
    Character(string, int, int, int, int, int, Vector2f, string);
    
    Vector2f getPosition();
    void setPosition(Vector2f);
    
    Vector2f getSize();
    void setSize(Vector2f);
    
    string getTexture();
    
    void update(float deltaTime);
private:
    // Vars
    string name;
    int experience;
    int life;
    int starvation;
    int irrigation;
    int lifeEnergy;
    
    Vector2f position;
    Vector2f size;
    Vector2f movementVector;
    string characterTexture;
};

#endif /* Character_hpp */
