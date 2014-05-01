/*
 * PlayerViewModel.cpp
 *
 * Created on: 1-mei-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "PlayerViewModel.hpp"

PlayerViewModel::PlayerViewModel(Player *player, QObject *parent) : QObject(parent) {
    this->player = player;
}

int PlayerViewModel::getID() const {
    return this->player->getID();
}

const QString& PlayerViewModel::getName() const {
    return this->player->getName();
}

