#ifndef HERO_H
#define HERO_H

#include "creature.h"
#include <QApplication>

class Hero : public Creature
{

private:
       Hero(size_t countSkin = 3);
       Hero(const Hero &);
       Hero &operator=(Hero &);
public:
        virtual ~Hero();
        static Hero *instance(size_t countSkin = 3);
        virtual Creature::Type type() { return Type::Hero; }

        int getMaxJumpingEdge() const { return m_maxJumpingEdge; }

private:
        const int m_maxJumpingEdge = 200;
};

#endif // HERO_H
