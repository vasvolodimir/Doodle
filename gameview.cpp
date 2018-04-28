#include "gameview.h"

GameView::GameView(QWidget *parent)
{
    m_scene = new QGraphicsScene(parent->rect());
    this->setScene(m_scene);

    initView();
    createHero();
}

GameView *GameView::instance(QWidget *parent)
{
    static GameView *instance = new GameView(parent);
    return instance;
}

GameView::~GameView()
{
    delete m_scene;
    delete m_heroManager;
    delete instance();

    for(int i=0; i<m_bricks.size(); i++)
        delete m_bricks[i];
}

void GameView::initView()
{
    // FIXME: Change the magic number
    generateBricks(bricksCount);
    m_bricksManager = new BricksMoveManager(m_bricks, this);

    // sets the background-color
    this->setStyleSheet("background: rgb(163, 193, 245);");
}

void GameView::generateBricks(const int count)
{
    srand(time(NULL));

    for(int i=0; i<count; i++)
        generate();

    LOG_D("");
}

bool GameView::generate()
{
    SolideBrick *item = new SolideBrick(QRectF(X, Y, Width, Height));
    bool correct = false;

    while(true)
    {
        int x = rand() % (width() - Width);
        int y = rand() % (height() - Height);

        item->setPos(x, y);

        for(int i=0; i<m_bricks.size(); i++)
        {
            if(m_bricks[i]->collidesWithItem(item))
                break;

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

void GameView::createHero()
{
    m_scene->addItem(Hero::instance(3));
    m_heroManager = new HeroMoveManager(this);
}

void GameView::keyPressEvent(QKeyEvent *event)
{
    m_heroManager->handleKeyEvent(event);
}
