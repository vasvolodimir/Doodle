#ifndef HEROMOVEMANAGER_H
#define HEROMOVEMANAGER_H

#include <QTimer>
#include <QObject>
#include <QKeyEvent>

#include "gameview.h"
#include "solidebrick.h"
#include "hero.h"
#include "BricksMoveManager.h"

#define yOffset 50

class GameView;
class SolideBrick;
class Hero;
class BricksMoveManager;

class HeroMoveManager : public QObject
{
    Q_OBJECT

public:
        HeroMoveManager(BricksMoveManager *manager, QObject *parent = 0);
        ~HeroMoveManager();
        void handleKeyEvent(QKeyEvent *event);

private:
        void initPosition();

private:
        BricksMoveManager *m_bricksManager;
        Hero *m_hero;
        QTimer *m_timer;

private slots:
            void Jumping();
};

#endif // HEROMOVEMANAGER_H
