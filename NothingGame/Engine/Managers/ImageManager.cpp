//
// Created by Mateusz Pelka on 07.03.2017.
//

#include "ImageManager.hpp"
#include "../../ResourcePath.hpp"

void ImageManager::loadTexture(const string& name, const string& filename) {
    if (textures.find(name) == textures.end()) {
        Texture tex;
        tex.loadFromFile(resourcePath() + filename);

        this->textures[name] = tex;
    }

    return;
}

Texture& ImageManager::getRef(const string& texture) {
    return this->textures.at(texture);
}
