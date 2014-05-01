/*
 * LoginViewModel.cpp
 *
 * Created on: 1-mei-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "LoginViewModel.hpp"

LoginViewModel::LoginViewModel(TicTacService *service, QObject *parent) : ViewModel(parent) {
    this->service = service;
}

void LoginViewModel::login(const QString& username) {
    this->service->login(username);
}
