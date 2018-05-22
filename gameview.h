#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include <QDebug>

#include <ctime>

#include "solidebrick.h"
#include "mainscreen.h"
#include "logger.h"
#include "hero.h"
#include "HeroMoveManager.h"
#include "BricksMoveManager.h"

class HeroMoveManager;
class BricksMoveManager;
class Hero;

class GameView : public QGraphicsView
{
    Q_OBJECT

    public:  
             GameView(QWidget *parent = 0);
            ~GameView();

             QGraphicsScene *getScene() const { return m_scene; }

    private:
            QGraphicsScene *m_scene;
            HeroMoveManager *m_heroManager;
            BricksMoveManager *m_bricksManager;

    private:
            void initView();
            void createHero();

    protected:
                void keyPressEvent(QKeyEvent *event);
                void keyReleaseEvent(QKeyEvent *event);

    signals:
             void timerStart();

};

#endif // GAMEVIEW_H
