#include "mainscreen.h"

MainScreen::MainScreen(QWidget *parent): QDialog(parent)
{
    initScreen();
}

MainScreen::~MainScreen()
{

}

MainScreen *MainScreen::instance(QWidget *parent)
{
    static MainScreen *instance = new MainScreen(parent);
    return instance;
}

void MainScreen::initScreen()
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(GameView::instance(this));
    layout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(layout);

    this->setFixedSize(Width, Height);
}
