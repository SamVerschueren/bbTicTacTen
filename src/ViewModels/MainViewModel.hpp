/*
 * MainViewModel.hpp
 *
 * Created on: 27-apr.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef MAINVIEWMODEL_HPP_
#define MAINVIEWMODEL_HPP_

#include <QObject>
#include <bb/cascades/GroupDataModel>

#include "TicTacService.hpp"

#include "ViewModel.hpp"

#include "Player.hpp"

using namespace bb::cascades;

class MainViewModel : public ViewModel
{
    Q_OBJECT

    Q_PROPERTY(GroupDataModel* playerModel READ getPlayerModel NOTIFY playerModelChanged)

    Q_SIGNALS:
        void playerModelChanged(GroupDataModel* dataModel);
        void playerChallenged(int id, const QString& name);

    private:
        TicTacService* service;

        GroupDataModel* playerModel;

        int id;
        Player* you;

    public:
        MainViewModel(TicTacService* service, QObject *parent=0);

        GroupDataModel* getPlayerModel();

        Q_INVOKABLE void challenge(int id);

    private slots:
        void onIDReceived(int id);
        void onPlayerListRetrieved(const QList<Player*>& players);
        void onPlayerChallenged(int id, const QString& name);
};


#endif /* MAINVIEWMODEL_HPP_ */
