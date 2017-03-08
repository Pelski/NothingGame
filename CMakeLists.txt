cmake_minimum_required(VERSION 3.6)
project(NothingGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES
        NothingGame/Engine/Managers/EventManager.cpp
        NothingGame/Engine/Managers/EventManager.hpp
        NothingGame/Engine/Managers/WindowManager.cpp
        NothingGame/Engine/Managers/WindowManager.hpp

        NothingGame/Engine/GameObjects/Character.cpp
        NothingGame/Engine/GameObjects/Character.hpp

        NothingGame/Engine/Scenes/TestScene.cpp
        NothingGame/Engine/Scenes/TestScene.hpp
        NothingGame/Engine/Scenes/SplashScreen.cpp
        NothingGame/Engine/Scenes/SplashScreen.hpp

        NothingGame/Resources/icon.png
        NothingGame/Resources/Caution.png

        NothingGame/main.cpp
        NothingGame/ResourcePath.hpp NothingGame/Engine/Managers/ImageManager.cpp NothingGame/Engine/Managers/ImageManager.hpp)

add_executable(NothingGame ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(NothingGame ${SFML_LIBRARIES})
endif()