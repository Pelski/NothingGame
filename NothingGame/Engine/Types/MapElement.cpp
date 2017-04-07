//
// Created by Mateusz Pelka on 07.04.2017.
//

#include "MapElement.h"

const Vector2i &MapElement::getPosition() const {
    return position;
}

void MapElement::setPosition(const Vector2i &position) {
    MapElement::position = position;
}

int MapElement::getBackground() const {
    return background;
}

void MapElement::setBackground(int background) {
    MapElement::background = background;
}

int MapElement::getUserLevel() const {
    return userLevel;
}

void MapElement::setUserLevel(int userLevel) {
    MapElement::userLevel = userLevel;
}

int MapElement::getForeground() const {
    return foreground;
}

void MapElement::setForeground(int foreground) {
    MapElement::foreground = foreground;
}

