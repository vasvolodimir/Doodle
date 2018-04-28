#ifndef BRICKSMOVEMANAGER_H
#define BRICKSMOVEMANAGER_H

#include <QObject>
#include <QTimer>

#include "solidebrick.h"
#include "hero.h"
#include "gameview.h"
#include <unistd.h>

class SolideBrick;
class Hero;

class BricksMoveManager : public QObject
{
   Q_OBJECT

    enum timerKind {Main, Scrolling};

public:
        BricksMoveManager(QVector<SolideBrick*> &bricks, QObject *parent = 0);
        ~BricksMoveManager();

private slots:
        void calcFirstAndSecondBrick();
        void scrollBricks();

private:
        QTimer *createTimer(timerKind kind, int interval, QTimer **timer);

private:
        QVector<SolideBrick*> m_bricks;
        SolideBrick *m_firstBrick;
        SolideBrick *m_secondBrick;
        unsigned m_difference;
private:
        QTimer *m_timerMain;
        QTimer *m_timerScrolling;

};

#endif // BRICKSMOVEMANAGER_H
