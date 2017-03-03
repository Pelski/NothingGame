//
//  EventManager.cpp
//  NothingGame
//
//  Created by Mateusz Pelka on 01.03.2017.
//  Copyright © 2017 Pelski. All rights reserved.
//

#include "EventManager.hpp"

EventManager::EventHandle EventManager::handleEvent() {
    switch (event.type) {
        case Event::Closed:
            return EventHandle::WINDOW_CLOSE;
        case sf::Event::KeyPressed:
            // Parse key pressed
            if (event.key.code == Keyboard::Escape)
                return EventHandle::WINDOW_CLOSE;
            break;
        default:
            return EventHandle::NOTHING;
    }
}
