/*
 * ConnectionService.hpp
 *
 * Created on: 24-apr.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef CONNECTIONSERVICE_HPP_
#define CONNECTIONSERVICE_HPP_

#include <QTcpSocket>
#include <QObject>

class ConnectionService : public QObject
{
    Q_OBJECT

    private:
        QTcpSocket *socket;

    public:
        ConnectionService(QObject *parent=0);

        void connectToHost(const QString& host, int port);

    private slots:
        void onSocketConnected();
        void onSocketDisconnected();
        void onSocketError(QAbstractSocket::SocketError error);
};

#endif /* CONNECTIONSERVICE_HPP_ */
