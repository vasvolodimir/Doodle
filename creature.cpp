#include "creature.h"

Creature::~Creature()
{
    for(int i=0; i<m_skins.size(); i++)
        delete m_skins[i];
}

void Creature::setLeftSkin(QPixmap *pixmap)
{
    if(getLeftSkin() == pixmap || m_skins.size() < LEFT)
        return;

    m_skins[LEFT] = pixmap;
}

void Creature::setRightSkin(QPixmap *pixmap)
{
    if(getRightSkin() == pixmap || m_skins.size() < RIGHT)
        return;

    m_skins[RIGHT] = pixmap;
}

void Creature::setFrontSkin(QPixmap *pixmap)
{
    if(getFrontSkin() == pixmap || m_skins.size() < FRONT)
        return;

    m_skins[FRONT] = pixmap;
}
