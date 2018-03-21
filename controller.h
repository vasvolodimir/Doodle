#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "mainscreen.h"

class Controller : public QObject
{
     Q_OBJECT

public:
        Controller(QObject *parent = 0);
        ~Controller();

public:
        static MainScreen *getMainScreen() { return MainScreen::instance(); }

private:
        MainScreen *m_MainScreen;
};

#endif // CONTROLLER_H
