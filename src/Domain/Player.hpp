/*
 * Player.hpp
 *
 * Created on: 1-mei-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <QObject>

class Player : public QObject
{
    Q_OBJECT

    private:
        int id;
        QString name;

    public:
        Player(int id, const QString& name);

        int getID() const;
        void setID(int id);

        const QString& getName() const;
        void setName(const QString& name);
};

#endif /* PLAYER_HPP_ */
