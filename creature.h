#ifndef CREATURE_H
#define CREATURE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QVector>

#include "logger.h"

class Creature : public QGraphicsPixmapItem
{

protected:
    enum Type { Hero };
    enum Skin { LEFT, RIGHT, FRONT};

public:
        Creature(size_t countSkin = 3) : countSkin(countSkin) { m_skins.resize(countSkin); LOG_D(countSkin);}
        virtual Type type() = 0;
        virtual ~Creature();

        QPixmap *getLeftSkin() const { return (m_skins.size() >= 1) ? m_skins.at(LEFT) : nullptr; }
        QPixmap *getRightSkin() const { return (m_skins.size() >= 2) ? m_skins.at(RIGHT) : nullptr; }
        QPixmap *getFrontSkin() const { return (m_skins.size() >= 3) ? m_skins.at(FRONT) : nullptr; }

        void setLeftSkin(QPixmap *pixmap);
        void setRightSkin(QPixmap *pixmap);
        void setFrontSkin(QPixmap *pixmap);

private:
        QVector<QPixmap*> m_skins;
        const size_t countSkin;
};

#endif // CREATURE_H
