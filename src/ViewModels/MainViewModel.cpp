/*
 * MainViewModel.cpp
 *
 * Created on: 27-apr.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "MainViewModel.hpp"
#include "PlayerViewModel.hpp"

MainViewModel::MainViewModel(TicTacService* service, QObject *parent) : ViewModel(parent), id(0), you(NULL) {
    this->service = service;
    connect(service, SIGNAL(onIDReceived(int)), this, SLOT(onIDReceived(int)));
    connect(service, SIGNAL(onPlayerListRetrieved(QList<Player*>)), this, SLOT(onPlayerListRetrieved(QList<Player*>)));
    connect(service, SIGNAL(onPlayerChallenged(int, QString)), this, SLOT(onPlayerChallenged(int, QString)));

    this->playerModel = new GroupDataModel(QStringList() << "name", this);
}

GroupDataModel* MainViewModel::getPlayerModel() {
    return this->playerModel;
}

void MainViewModel::challenge(int id) {
    this->service->challenge(id);
}

void MainViewModel::onIDReceived(int id) {
    this->id = id;

    this->setState(ViewState::LOADING);

    this->service->retrieveList();
}

void MainViewModel::onPlayerListRetrieved(const QList<Player*>& players) {
    this->playerModel->clear();

    foreach(Player *player, players) {
        if(this->id == player->getID()) {
            this->you = player;
        }
        else {
            this->playerModel->insert(new PlayerViewModel(player, this));
        }
    }

    this->setState(ViewState::DEFAULT);
}

void MainViewModel::onPlayerChallenged(int id, const QString& name) {
    this->playerChallenged(id, name);
}
