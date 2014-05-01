/*
 * LoginViewModel.hpp
 *
 * Created on: 1-mei-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef LOGINVIEWMODEL_HPP_
#define LOGINVIEWMODEL_HPP_

#include "TicTacService.hpp"

#include "ViewModel.hpp"

class LoginViewModel: public ViewModel
{
    Q_OBJECT

    private:
        TicTacService *service;

    public:
        LoginViewModel(TicTacService *service, QObject *parent=0);

        Q_INVOKABLE void login(const QString& username);
};

#endif /* LOGINVIEWMODEL_HPP_ */
