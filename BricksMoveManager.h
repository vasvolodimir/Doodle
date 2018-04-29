#ifndef BRICKSMOVEMANAGER_H
#define BRICKSMOVEMANAGER_H

#include <QObject>
#include <QTimer>

#include <ctime>

#include "solidebrick.h"
#include "hero.h"
#include "gameview.h"
#include "logger.h"

class SolideBrick;
class Hero;

class BricksMoveManager : public QObject
{
   Q_OBJECT

    enum timerKind {Main, Scrolling};
    enum initGeometry : unsigned {X = 0, Y = 0, Width = 100, Height = 20};
    const unsigned bricksCount = 20;

public:
        BricksMoveManager(QObject *parent = 0);
        ~BricksMoveManager();

        QVector<SolideBrick*> getBricks() const { return m_bricks; }

private slots:
        void calcFirstAndSecondBrick();
        void scrollBricks();

private:
        QTimer *createTimer(timerKind kind, int interval, QTimer **timer);
        void generateBricks(const int count);
        bool generate();

private:
        QVector<SolideBrick*> m_bricks;
        SolideBrick *m_firstBrick;
        SolideBrick *m_secondBrick;
        unsigned m_difference;
private:
        QTimer *m_timerMain;
        QTimer *m_timerScrolling;
        QObject *m_parent;

};

#endif // BRICKSMOVEMANAGER_H
