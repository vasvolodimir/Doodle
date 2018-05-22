#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
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
             QGraphicsItem *getLeftBorder() const { return m_leftBorder; }
             QGraphicsItem *getRightBorder() const { return m_rightBorder; }
             QGraphicsItem *getBottomBorder() const { return m_bottomBorder; }

    private:
            QGraphicsScene *m_scene;
            HeroMoveManager *m_heroManager;
            BricksMoveManager *m_bricksManager;
            QGraphicsLineItem *m_leftBorder;
            QGraphicsLineItem *m_rightBorder;
            QGraphicsLineItem *m_bottomBorder;

    private:
            void initView();
            void createHero();
            void createBorders();

    protected:
                void keyPressEvent(QKeyEvent *event);

    signals:
             void timerStart();

};

#endif // GAMEVIEW_H
