#ifndef HERO_H
#define HERO_H

#include "creature.h"
#include <QApplication>

class Hero : public Creature
{

public:
        Hero(size_t countSkin = 3);
        virtual Creature::Type type() { return Type::Hero; }
};

#endif // HERO_H
