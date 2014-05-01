/*
 * Player.cpp
 *
 * Created on: 1-mei-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "Player.hpp"

Player::Player(int id, const QString& name) : id(id), name(name) {

}

void Player::setID(int id) {
    this->id = id;
}

int Player::getID() const {
    return this->id;
}

void Player::setName(const QString& name) {
    this->name = name;
}

const QString& Player::getName() const {
    return this->name;
}
