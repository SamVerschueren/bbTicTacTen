/*
 * ViewModel.cpp
 *
 * Created on: 15-mrt.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "ViewModel.hpp"

ViewModel::ViewModel(QObject* parent) : QObject(parent), state(ViewState::DEFAULT) {

}

int ViewModel::getState() const {
    return this->state;
}

void ViewModel::setState(int state) {
    this->state = state;

    emit stateChanged(state);
}
