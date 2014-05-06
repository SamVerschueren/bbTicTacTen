/*
 * TicTacService.cpp
 *
 * Created on: 1-mei-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include <QRegExp>
#include <QStringList>

#include "TicTacService.hpp"

TicTacService::TicTacService(QObject *parent) : QObject(parent) {
    this->socket = new QTcpSocket(this);
    connect(this->socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
    connect(this->socket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
    connect(this->socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(onDataReceived()));
}

TicTacService::~TicTacService() {
    this->socket->disconnectFromHost();
    this->socket->close();
}

void TicTacService::connectToHost(const QHostAddress& host, int port) {
    this->socket->connectToHost(host, port);
}

void TicTacService::login(const QString& username) {
    QString data = QString("HELO %1").arg(username);

    socket->write(data.toAscii());
    socket->flush();
}

void TicTacService::retrieveList() {
    socket->write("LIST");
    socket->flush();
}

void TicTacService::challenge(int id) {
    QString data = QString("CHAL %1").arg(id);

    socket->write(data.toAscii());
    socket->flush();
}

void TicTacService::onSocketConnected() {
    qDebug() << "Socket succesfully connected";
}

void TicTacService::onSocketDisconnected() {
    qDebug() << "Socket disconnected";
}

void TicTacService::onSocketError(QAbstractSocket::SocketError error) {
    qDebug() << "A socket error occurred " << error;
}

void TicTacService::onDataReceived() {
    QString line = socket->readAll();

    int position = line.indexOf(QRegExp("[\r\n]"));

    if(position == -1) {
        position = line.indexOf(' ');
    }

    qDebug() << "Received " << line;

    qDebug() << "Position of newline: " << position;

    if(position > 0) {
        this->handleAction(line.mid(0, position), line.mid(position+1).trimmed());
    }
}

void TicTacService::handleAction(const QString& action, const QString& data) {
    qDebug() << "Action: " << action;
    qDebug() << "Data: " << data;

    if(action == "HI") {
        this->onIDReceived(data.toInt());
    }
    else if(action == "LIST") {
        QStringList list = data.split(QRegExp("[\r\n]"), QString::SkipEmptyParts);

        QList<Player*> players;

        foreach(QString user, list) {
            int position = user.indexOf(' ');

            players << new Player(user.mid(0, position).toInt(), user.mid(position+1));
        }

        this->onPlayerListRetrieved(players);
    }
    else if(action == "CHALV") {
        int position = data.indexOf(' ');

        this->onPlayerChallenged(data.mid(0, position).toInt(), data.mid(position+1));
    }
}
