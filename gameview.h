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
#include "BricksMoveManager.h"

class HeroMoveManager;
class BricksMoveManager;
class Hero;

class GameView : public QGraphicsView
{
    Q_OBJECT

    GameView(QWidget *parent = 0);
    GameView(const GameView &);
    GameView &operator=(GameView&);

    enum initGeometry : unsigned {X = 0, Y = 0, Width = 100, Height = 20};
    const unsigned bricksCount = 20;

    public:
             static GameView *instance(QWidget *parent = 0);

             QGraphicsScene *getScene() const { return m_scene; }
             QVector<SolideBrick*> getBricks() const { return m_bricks; }

            ~GameView();

    private:
            // TODO: if param ctor is needed - use NOT-Mayers singleton
            static GameView *m_instance;
            QGraphicsScene *m_scene;
            QVector<SolideBrick*> m_bricks;
            HeroMoveManager *m_heroManager;
            BricksMoveManager *m_bricksManager;

    private:
            void initView();
            void generateBricks(const int count);
            bool generate();
            void createHero();

    protected:
                void keyPressEvent(QKeyEvent *event);

};

#endif // GAMEVIEW_H
