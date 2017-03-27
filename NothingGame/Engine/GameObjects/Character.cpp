//
//  Character.cpp
//  NothingGame
//
//  Created by Mateusz Pelka on 06.03.2017.
//  Copyright © 2017 Pelski. All rights reserved.
//

#include "Character.hpp"

/**
 *
 * @param name Character name
 * @param experience Experience points
 * @param life Life points
 * @param starvation Starvation level (percentage)
 * @param thirst Thirst level (percentage)
 * @param lifeEnergy Life Energy level (percentage)
 * @param position Position of character
 * @param size Size of collision box
 * @param characterTexture Character texture name
 */
void Character::create(
        string name,
        int experience,
        int life,
        int starvation,
        int thirst,
        int lifeEnergy,
        Vector2f position,
        Vector2f size,
        string characterTexture) {
    this->name = name;
    this->experience = experience;
    this->life = life;
    this->starvation = starvation;
    this->thirst = thirst;
    this->lifeEnergy = lifeEnergy;
    this->position = position;
    this->characterTexture = characterTexture;
    this->size = size;
    this->movementVector = Vector2f(0.0f, 0.0f);

    this->speed = 20.0f;
    this->maxSpeed = 80.0f;
    this->isCrouching = false;
}

Vector2f Character::getPosition() {
    return position;
}

void Character::setPosition(Vector2f position) {
    this->position = position;
}

string Character::getTexture() {
    return characterTexture;
}

void Character::addVector(Vector2f vector) {
    this->movementVector = Vector2f(this->movementVector.x + vector.x, this->movementVector.y + vector.y);
}

void Character::update(float deltaTime) {
    // Fixing X axis movement vector
    if (movementVector.x < -5.0f)
        movementVector.x += 500.0f * deltaTime;
    else if (movementVector.x > 5.0f)
        movementVector.x -= 500.0f * deltaTime;
    else
        movementVector.x = 0.0f;

    if (movementVector.x > maxSpeed)
        movementVector.x = maxSpeed;

    if (movementVector.x < -maxSpeed)
        movementVector.x = -maxSpeed;

    // Fixing Y axis movement vector
    if (movementVector.y < 200.0f)
        movementVector.y += 750.0f * deltaTime;

    // Temp!
    if (this->position.y >= 970.0f && this->movementVector.y >= 0.0f) {
        this->position.y = 970.0f;
        movementVector.y = 0.0f;
    }

    if (this->position.x > 1835.0f) {
        this->position.x = 1835.0f;
        movementVector.x = 0.0f;
    }

    if (this->position.x < 10.0f) {
        this->position.x = 10.0f;
        movementVector.x = 0.0f;
    }
    // End Temp!

    // Changing position of Character
    this->position.x += movementVector.x * deltaTime * 10.0f;
    this->position.y += movementVector.y * deltaTime * 10.0f;

    if (this->isCrouching) {
        this->position.y += 25.0f;
        this->size.y = 75.0f;
        this->isCrouching = false;
    } else {
        this->size.y = 100.0f;
    }
}

void Character::moveLeft() {
    movementVector.x -= speed;
}

void Character::moveRight() {
    movementVector.x += speed;
}

void Character::jump() {
    if (movementVector.y == 0.0f) {
        movementVector.y -= 250.0f;
    }
}

void Character::crouch() {
    this->isCrouching = true;
}

float Character::getVerticalSpeed() {
    return movementVector.y;
}

void Character::draw(RenderTarget *target) {
    RectangleShape rectangleShape(this->size);
    rectangleShape.setFillColor(Color::Red);
    rectangleShape.setPosition(this->position);

    target->draw(rectangleShape);
}