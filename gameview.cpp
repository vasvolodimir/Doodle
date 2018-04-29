#include "gameview.h"

GameView::GameView(QWidget *parent)
    : QGraphicsView(parent),
      m_scene(0),
      m_heroManager(0),
      m_bricksManager(0)
{
    m_scene = new QGraphicsScene(parent->rect());
    this->setScene(m_scene);

    initView();
    createHero();
}

GameView::~GameView()
{
    delete m_scene;
    delete m_heroManager;
    delete m_bricksManager;
}

void GameView::initView()
{
    m_bricksManager = new BricksMoveManager(m_scene);

    // sets the background-color
    this->setStyleSheet("background: rgb(163, 193, 245);");
}

void GameView::createHero()
{
    m_scene->addItem(Hero::instance(3));
    m_heroManager = new HeroMoveManager(m_bricksManager, m_scene);
}

void GameView::keyPressEvent(QKeyEvent *event)
{
    m_heroManager->handleKeyEvent(event);
}
