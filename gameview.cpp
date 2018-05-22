#include "gameview.h"

GameView::GameView(QWidget *parent)
    : QGraphicsView(parent),
      m_scene(0),
      m_heroManager(0),
      m_bricksManager(0),
      m_leftBorder(0),
      m_rightBorder(0),
      m_bottomBorder(0)
{
    m_scene = new QGraphicsScene(this);
    m_scene->setSceneRect(parent->rect());
    this->setScene(m_scene);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    initView();
    createHero();
}

GameView::~GameView()
{
    delete m_scene;
    delete m_heroManager;
    delete m_bricksManager;
    delete m_leftBorder;
    delete m_rightBorder;
    delete m_bottomBorder;
}

void GameView::initView()
{
    m_bricksManager = new BricksMoveManager(m_scene);
    createBorders();

    LOG_D("GameView: " << m_scene);

    // sets the background-color
    this->setStyleSheet("background: rgb(163, 193, 245);");
}

void GameView::createHero()
{
    m_scene->addItem(Hero::instance(3));
    m_heroManager = new HeroMoveManager(m_bricksManager, m_scene);
    emit timerStart();
}

void GameView::createBorders()
{
    m_leftBorder = new QGraphicsLineItem(x(), y(), x(), m_scene->height());
    m_rightBorder = new QGraphicsLineItem(m_scene->width(), y(), m_scene->width(), m_scene->height());
    m_bottomBorder = new QGraphicsLineItem(x(), m_scene->height(), m_scene->width(), m_scene->height());

    m_scene->addItem(m_leftBorder);
    m_scene->addItem(m_rightBorder);
    m_scene->addItem(m_bottomBorder);
}

void GameView::keyPressEvent(QKeyEvent *event)
{
    m_heroManager->handleKeyEvent(event);
}
