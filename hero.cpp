#include "hero.h"


Hero::Hero(size_t countSkin) : Creature(countSkin)
{
    this->setLeftSkin(new QPixmap(QApplication::applicationDirPath() + "/resources/left.png"));
    this->setRightSkin(new QPixmap(QApplication::applicationDirPath() + "/resources/right.png"));
    this->setFrontSkin(new QPixmap(QApplication::applicationDirPath() + "/resources/up.png"));
    this->setPixmap(*getLeftSkin());
}

Hero::~Hero()
{
    delete instance();
}

Hero *Hero::instance(size_t countSkin)
{
    static Hero *instance = new Hero(countSkin);
    return instance;
}


