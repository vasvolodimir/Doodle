#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include <QDebug>

#include <ctime>
#include "solidebrick.h"

class GameView : public QGraphicsView
{
    Q_OBJECT

    GameView(QWidget *parent = 0);
    GameView(const GameView &);
    GameView &operator=(GameView&);

    enum initGeometry : unsigned {X = 0, Y = 0, Width = 100, Height = 20};

    public:
             static GameView *instance(QWidget *parent = 0);
            ~GameView();

    private:
            QGraphicsScene *m_scene;
            QVector<SolideBrick*> m_bricks;

    private:
            void initView();
            void generateBricks(const int count);
            bool generate();

};

#endif // GAMEVIEW_H
