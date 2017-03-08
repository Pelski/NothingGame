//
//  EventManager.hpp
//  NothingGame
//
//  Created by Mateusz Pelka on 01.03.2017.
//  Copyright © 2017 Pelski. All rights reserved.
//

#ifndef EventManager_hpp
#define EventManager_hpp

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class EventManager {
public:
    // Vars
    enum EventHandle : int {
        NOTHING,
        WINDOW_CLOSE,
        WINDOW_RESIZE,
        WINDOW_FOCUS_LOST,
        WINDOW_FOCUS_GAIN
    };
    Event event;

    // Methods
    EventHandle handleEvent();
};

#endif /* EventManager_hpp */
