#include "gameview.h"

GameView::GameView(QWidget *parent)
{
    m_scene = new QGraphicsScene(parent->rect());
    this->setScene(m_scene);

    initView();
}

GameView *GameView::instance(QWidget *parent)
{
    static GameView *instance = new GameView(parent);
    return instance;
}

GameView::~GameView()
{

}

void GameView::initView()
{
    // FIXME: Change the magic number
    generateBricks(10);

    // sets the background-color
    this->setStyleSheet("background: rgb(163, 193, 245);");
}

void GameView::generateBricks(const int count)
{
    srand(time(NULL));

    for(int i=0; i<count; i++)
        generate();
}

bool GameView::generate()
{
    SolideBrick *item = new SolideBrick(QRectF(X, Y, Width, Height));
    bool correct = false;

    while(true)
    {
        item->setPos(rand() % (width() - 100), rand() % (height() - 20));

        for(int i=0; i<m_bricks.size(); i++)
        {
            if(m_bricks[i]->collidesWithItem(item))
            {
                qDebug() << "colide";
                break;
            }

            if(i == m_bricks.size() - 1)
                correct = true;
        }

        if(correct || !m_bricks.size())
        {
            m_bricks.push_back(item);
            // FIXME: It looks strange from OOP view point
            m_scene->addItem(item);
            m_scene->addItem(item->getColideLine());
            m_scene->addItem(item->getUnColideLine());
            return true;
        }

    }

    return false;
}
