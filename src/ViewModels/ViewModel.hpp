/*
 * ViewModel.hpp
 *
 * Created on: 15-mrt.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef VIEWMODEL_HPP_
#define VIEWMODEL_HPP_

#include <QObject>
#include "ViewState.hpp"

class ViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int state READ getState NOTIFY stateChanged FINAL)

    Q_SIGNALS:
        void stateChanged(int state);

    private:
        int state;

    protected:
        void setState(int state);

    public:
        ViewModel(QObject* parent=0);

        int getState() const;
};

#endif /* VIEWMODEL_HPP_ */
