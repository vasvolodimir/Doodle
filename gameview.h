#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include <QDebug>

#include <ctime>
#include "solidebrick.h"
#include "logger.h"
#include "hero.h"
#include "HeroMoveManager.h"

class HeroMoveManager;
class Hero;

class GameView : public QGraphicsView
{
    Q_OBJECT

    GameView(QWidget *parent = 0);
    GameView(const GameView &);
    GameView &operator=(GameView&);

    enum initGeometry : unsigned {X = 0, Y = 0, Width = 100, Height = 20};

    public:
             static GameView *instance(QWidget *parent = 0);

             QGraphicsScene *getScene() { return m_scene; }
             Hero *getHero() { return m_hero; }
             QVector<SolideBrick*> getBricks() { return m_bricks; }

            ~GameView();

    private:
            QGraphicsScene *m_scene;
            QVector<SolideBrick*> m_bricks;
            Hero *m_hero;
            HeroMoveManager *m_heroManager;

    private:
            void initView();
            void generateBricks(const int count);
            bool generate();
            void createHero();

    protected:
                void keyPressEvent(QKeyEvent *event);

};

#endif // GAMEVIEW_H
