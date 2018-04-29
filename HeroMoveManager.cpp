#include "HeroMoveManager.h"

HeroMoveManager::HeroMoveManager(BricksMoveManager *manager, QObject *parent)
    : QObject(parent),
      m_bricksManager(manager),
      m_hero(Hero::instance())
{
    initPosition();

    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(Jumping()));

    // TODO: Looking for a good value of timer interval
    m_timer->setInterval(5);
    m_timer->start();

    connect(m_bricksManager, SIGNAL(timerStart()), m_timer, SLOT(start()));
    connect(m_bricksManager, SIGNAL(timerStop()), m_timer, SLOT(stop()));
}

HeroMoveManager::~HeroMoveManager()
{

}

// TODO: A movemanet logic should be refactoring
void HeroMoveManager::handleKeyEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
        for(int i=0; i<10; i++)
            m_hero->setPos(m_hero->x() - 1, m_hero->y());

    if(event->key() == Qt::Key_D)
        for(int i=0; i<10; i++)
            m_hero->setPos(m_hero->x() + 1, m_hero->y());
}

void HeroMoveManager::initPosition()
{
    QVector<SolideBrick*> bricks = m_bricksManager->getBricks();
    SolideBrick *max = bricks.at(0);

    for(int i=1; i<bricks.size(); i++)
        if(max->y() < bricks[i]->y())
            max = bricks[i];

    m_hero->setPos(max->x(), max->y() - m_hero->getLeftSkin()->height() - yOffset);
}

void HeroMoveManager::Jumping()
{
    static QVector<SolideBrick*> bricks = m_bricksManager->getBricks();
    static int old_y = 0;
    static const int jumpEdge = 150;

    for(int i=0; i<bricks.size(); i++)
    {
        if(m_hero->collidesWithItem(bricks[i]->getColideLine()) &&
                !m_hero->collidesWithItem(bricks[i]->getUnColideLine()))
        {
            old_y = m_hero->y();
            break;
        }
    }

    if( old_y && qAbs(m_hero->y() - old_y) <= jumpEdge)
        m_hero->setPos(m_hero->x(), m_hero->y() - 1);
    else
    {
        old_y = 0;
        m_hero->setPos(m_hero->x(), m_hero->y() + 1);
    }
}
