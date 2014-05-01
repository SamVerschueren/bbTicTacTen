/*
 * PlayerViewModel.hpp
 *
 * Created on: 1-mei-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef PLAYERVIEWMODEL_HPP_
#define PLAYERVIEWMODEL_HPP_

#include <QObject>

#include "Player.hpp"

class PlayerViewModel: public QObject
{
    Q_OBJECT

    Q_PROPERTY(int id READ getID CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)

    private:
        Player *player;

    public:
        PlayerViewModel(Player *player, QObject *parent=0);

        int getID() const;
        const QString& getName() const;
};

#endif /* PLAYERVIEWMODEL_HPP_ */
