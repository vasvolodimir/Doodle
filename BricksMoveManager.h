#ifndef BRICKSMOVEMANAGER_H
#define BRICKSMOVEMANAGER_H

#include <QObject>
#include <QTimer>

#include <ctime>

#include "solidebrick.h"
#include "hero.h"
#include "gameview.h"
#include "logger.h"
#include "tools.h"

class SolideBrick;
class Hero;

class BricksMoveManager : public QObject
{
   Q_OBJECT

    enum timerType {Main, Scrolling};
    enum generateType {Initial, Additional};
    enum initGeometry : unsigned {X = 0, Y = 0, Width = 100, Height = 20};

    const unsigned initBricksCount = 15;
    const unsigned stepBricksCount = 3;

public:
        BricksMoveManager(QObject *parent = 0);
        ~BricksMoveManager();

        QVector<SolideBrick*> getBricks() const { return m_bricks; }

private slots:
        void calcFirstAndSecondBrick();
        void scrollBricks();

private:
        QTimer *createTimer(timerType type, int interval, QTimer **timer);
        void generateBricks(generateType type, std::pair<int, int> range, const int count);
        bool generate(generateType type, std::pair<int, int> range);
        void deleteBrick();

        void calcBrickPosition(std::pair<int, int> range, int x1, int y1, int &x2, int &y2  /*OUT*/); // for additional
        SolideBrick *findTopBrick() const;

private:
        QVector<SolideBrick*> m_bricks;
        SolideBrick *m_firstBrick;
        SolideBrick *m_secondBrick;
        unsigned m_difference;
private:
        QTimer *m_timerMain;
        QTimer *m_timerScrolling;
        QObject *m_parent;
        QGraphicsScene *m_scene;

signals:
        void timerStop();
        void timerStart();

};

#endif // BRICKSMOVEMANAGER_H
