#include "hero.h"


Hero::Hero(size_t countSkin) : Creature(countSkin)
{
    this->setLeftSkin(new QPixmap(QApplication::applicationDirPath() + "/resources/test.png"));
    this->setPixmap(*getLeftSkin());
}


