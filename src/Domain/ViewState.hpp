/*
 * Status.hpp
 *
 * Created on: 15-mrt.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef VIEWSTATE_HPP_
#define VIEWSTATE_HPP_

#include <QObject>

class ViewState : public QObject
{
    Q_OBJECT
    Q_ENUMS(State);

    public:
        enum State {
            DEFAULT,
            LOADING,

            ERROR,
            NETWORK_ERROR,
            ERROR_INCORRECT_PASSWORD
        };
};

#endif /* VIEWSTATE_HPP_ */
