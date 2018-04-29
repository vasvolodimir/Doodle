#include "mainscreen.h"

MainScreen::MainScreen(QWidget *parent): QDialog(parent)
{
    initScreen();
}

MainScreen::~MainScreen()
{
}

MainScreen *MainScreen::instance()
{
    static MainScreen instance;
    return &instance;
}

void MainScreen::initScreen()
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new GameView(this));
    layout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(layout);

    this->setFixedSize(Width, Height);
}
