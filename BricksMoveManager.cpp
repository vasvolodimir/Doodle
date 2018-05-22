#include "BricksMoveManager.h"

BricksMoveManager::BricksMoveManager(QObject *parent)
    : QObject(parent),
      m_bricks(0),
      m_firstBrick(0),
      m_secondBrick(0),
      m_timerMain(0),
      m_timerScrolling(0),
      m_parent(parent),
      m_scene(0)

{
    m_scene = qobject_cast<QGraphicsScene*> (m_parent);
    Q_ASSERT(m_scene);

    generateBricks(Initial, std::pair<int, int>(m_scene->width(),
                                                m_scene->height()), initBricksCount);

    createTimer(Main, 5, &m_timerMain);
    createTimer(Scrolling, 5, &m_timerScrolling);

     GameView *view = qobject_cast<GameView*> (m_parent->parent());
     Q_ASSERT(view);
     connect(view, SIGNAL(timerStart()), m_timerMain, SLOT(start()));

     LOG_D("GameView: " << m_scene);
}

BricksMoveManager::~BricksMoveManager()
{

}

void BricksMoveManager::calcFirstAndSecondBrick()
{
    if(!m_firstBrick || !m_secondBrick)
    {
        for(int i=0; i<m_bricks.size(); i++)
        {
            if(Hero::instance()->collidesWithItem(m_bricks[i]->getColideLine()) && !m_firstBrick)
            {
                m_firstBrick = m_bricks[i];
                LOG_D("First brick: " << m_firstBrick);
                return;
            }

            if(Hero::instance()->collidesWithItem(m_bricks[i]->getColideLine()) && !m_secondBrick
                    && m_bricks[i] != m_firstBrick && m_bricks[i]->y() < m_firstBrick->y())
            {
                m_secondBrick = m_bricks[i];
                LOG_D("Second brick: " << m_secondBrick);
                m_timerMain->stop();
            }
        }
    }

    if(m_firstBrick && m_secondBrick)
    {
        m_difference = 2 * (qAbs(m_secondBrick->y() - m_firstBrick->y()));

        generateBricks(Additional, std::pair<int, int>(m_scene->width(),
                                                       m_scene->height()), stepBricksCount);
        LOG_D("SIZE: " << m_bricks.size());

        emit timerStop(); // stop hero jumping
        m_timerScrolling->start();

        m_firstBrick = 0;
        m_secondBrick = 0;
    }
}

void BricksMoveManager::scrollBricks()
{
    if(m_difference)
    {
        for(int i=0; i<m_bricks.size(); i++)
            m_bricks[i]->setY(m_bricks[i]->y() + 1);

        m_difference--;
        LOG_D("Scrolling");
    }
    else
    {
        m_timerScrolling->stop();
        deleteBrick(); // all timers in this statment are disabled
        m_timerMain->start();
        emit timerStart(); // start hero moving
    }
}

void BricksMoveManager::calcBrickPosition(std::pair<int, int> range, int x1, int y1, int &x2, int &y2)
{
    do
    {
        x2 = rand() % ((int) range.first - Width);
        y2 = rand() % ((int) range.second /*/ 5*/ - Height);
        //y2 *= -1;
    }
    while(Tools::distance(x1, y1, x2, y2) > Hero::instance()->getMaxJumpingEdge());
}

SolideBrick *BricksMoveManager::findTopBrick() const
{
    SolideBrick *top = m_bricks.at(0);

    for(int i=1; i<m_bricks.size(); i++)
        if(top->y() > m_bricks.at(i)->y())
            top = m_bricks[i];

    return top;
}

QTimer *BricksMoveManager::createTimer(timerType type, int interval, QTimer **timer)
{

    *timer = new QTimer(this);
    (*timer)->setInterval(interval);

    switch (type)
    {
        case Main:
            connect(*timer, SIGNAL(timeout()), this, SLOT(calcFirstAndSecondBrick()));
            break;

        case Scrolling:
            connect(*timer, SIGNAL(timeout()), this, SLOT(scrollBricks()));
            break;

        default: break;
    }

    return *timer;
}

void BricksMoveManager::generateBricks(generateType type, std::pair<int, int> range, const int count)
{
    srand(time(NULL));

    for(int i=0; i<count; i++)
        generate(type, range);

    LOG_D("");
}

bool BricksMoveManager::generate(generateType type, std::pair<int, int> range)
{
    SolideBrick *item = new SolideBrick(QRectF(X, Y, Width, Height));
    bool correct = false;

        while(true)
        {
            int x, y;

            if(type == Initial)
            {
                x = rand() % ((int) range.first - Width);
                y = rand() % ((int) range.second - Height);
            }
            else
            {
//                x = rand() % ((int) range.first - Width);
//                y = rand() % ((int) range.second / 5 - Height);
//                y *= -1;

                SolideBrick *top = findTopBrick();
                calcBrickPosition(range, top->x(), top->y(), x, y);
            }

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

void BricksMoveManager::deleteBrick()
{
    for(int i=0; i<m_bricks.size(); i++)
        if(m_bricks[i]->y() >= m_scene->height())
        {
            SolideBrick *brick = m_bricks[i];
            m_scene->removeItem(brick->getColideLine());
            m_scene->removeItem(brick->getUnColideLine());
            m_scene->removeItem(brick);
            m_bricks.removeAt(i);
            delete brick;
            LOG_D("Deleted! Size: " << m_bricks.size());
        }
}
