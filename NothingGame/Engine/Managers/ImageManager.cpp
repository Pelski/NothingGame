//
// Created by Mateusz Pelka on 07.03.2017.
//

#include "ImageManager.hpp"
#include "../../ResourcePath.hpp"

void ImageManager::loadTexture(const string& textureName, const string& filename) {
    Texture tmpTexture;
    if (!tmpTexture.loadFromFile(resourcePath() + filename)) {
        return;
    }

    this->textures[textureName] = tmpTexture;
}

Texture& ImageManager::getTexture(const string& texture) {
    return this->textures.at(texture);
}