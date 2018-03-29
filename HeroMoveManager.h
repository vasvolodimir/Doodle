#ifndef HEROMOVEMANAGER_H
#define HEROMOVEMANAGER_H

#include <QTimer>
#include <QObject>

#include "gameview.h"
#include "solidebrick.h"
#include "hero.h"
#include <QKeyEvent>

#define yOffset 50

class GameView;
class SolideBrick;
class Hero;

class HeroMoveManager : public QObject
{
    Q_OBJECT

public:
        HeroMoveManager(GameView *view, QObject *parent = 0);
        ~HeroMoveManager();
        void handleKeyEvent(QKeyEvent *event);

private:
        void initPosition();

private:
        GameView *m_view;
        Hero *m_hero;
        QTimer *m_timer;

private slots:
            void Jumping();
};

#endif // HEROMOVEMANAGER_H
