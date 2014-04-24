/*
 * ConnectionService.cpp
 *
 * Created on: 24-apr.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "ConnectionService.hpp"

ConnectionService::ConnectionService(QObject *parent) : QObject(parent) {
    this->socket = new QTcpSocket();
    connect(this->socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
    connect(this->socket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
    connect(this->socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));

}

void ConnectionService::connectToHost(const QString& host, int port) {
    this->socket->connectToHost(host, port);


}

void ConnectionService::onSocketConnected() {
    qDebug() << "Socket succesfully connected";

    int i = 0;

    char *data=(char *)malloc(1024);
    int read=0;
    while((read=socket->read(data,1024))!=-1 && i < 10)
    {
        qDebug() << "Data read: " << data;

        i++;
    }

    this->socket->disconnectFromHost();
    this->socket->close();
}

void ConnectionService::onSocketDisconnected() {
    qDebug() << "Socket disconnected";
}

void ConnectionService::onSocketError(QAbstractSocket::SocketError error) {
    qDebug() << "A socket error occurred " << error;
}
