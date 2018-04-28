#include "BricksMoveManager.h"

BricksMoveManager::BricksMoveManager(QVector<SolideBrick *> &bricks, QObject *parent)
    : QObject(parent),
      m_bricks(bricks),
      m_firstBrick(0),
      m_secondBrick(0),
      m_timerMain(0),
      m_timerScrolling(0)

{
    createTimer(Main, 5, &m_timerMain);
    createTimer(Scrolling, 5, &m_timerScrolling);

    m_timerMain->start();
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
        m_difference = qAbs(m_secondBrick->y() - m_firstBrick->y());
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
        m_timerMain->start();
    }
}

QTimer *BricksMoveManager::createTimer(timerKind kind, int interval, QTimer **timer)
{

    *timer = new QTimer(this);
    (*timer)->setInterval(interval);

    switch (kind)
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
