/*
 * TicTacService.hpp
 *
 * Created on: 1-mei-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef TICTACSERVICE_HPP_
#define TICTACSERVICE_HPP_

#include <QTcpSocket>
#include <QHostAddress>
#include <QObject>

#include "Player.hpp"

class TicTacService: public QObject
{
    Q_OBJECT

    Q_SIGNALS:
        void onIDReceived(int id);
        void onPlayerListRetrieved(const QList<Player*>& players);
        void onPlayerChallenged(int id, const QString& name);

    private:
        QTcpSocket *socket;

        void handleAction(const QString& action, const QString& data);

    public:
        TicTacService(QObject *parent=0);
        ~TicTacService();

        void connectToHost(const QHostAddress& host, int port);

        void login(const QString& username);
        void retrieveList();
        void challenge(int id);

    private slots:
        void onSocketConnected();
        void onSocketDisconnected();
        void onSocketError(QAbstractSocket::SocketError error);
        void onDataReceived();
};

#endif /* TICTACSERVICE_HPP_ */
