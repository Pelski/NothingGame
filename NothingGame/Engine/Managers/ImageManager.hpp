//
// Created by Mateusz Pelka on 07.03.2017.
//

#ifndef NOTHINGGAME_IMAGEMANAGER_H
#define NOTHINGGAME_IMAGEMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

using namespace std;
using namespace sf;

class ImageManager {
public:
    void loadTexture(const string& textureName, const string &filename);
    Texture& getTexture(const string& texture);
private:
    map<string, Texture> textures;
};


#endif //NOTHINGGAME_IMAGEMANAGER_H
