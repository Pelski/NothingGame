//
// Created by Mateusz Pelka on 07.04.2017.
//

#ifndef NOTHINGGAME_MAPELEMENT_H
#define NOTHINGGAME_MAPELEMENT_H

#include <SFML/System.hpp>
using namespace sf;

class MapElement {
private:
    Vector2i position;
    int background;
    int userLevel;
    int foreground;

public:
    const Vector2i &getPosition() const;
    void setPosition(const Vector2i &position);
    int getBackground() const;
    void setBackground(int background);
    int getUserLevel() const;
    void setUserLevel(int userLevel);
    int getForeground() const;
    void setForeground(int foreground);
};


#endif //NOTHINGGAME_MAPELEMENT_H
