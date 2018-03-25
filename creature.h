#ifndef CREATURE_H
#define CREATURE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QVector>

class Creature : public QGraphicsPixmapItem
{
    enum Type { Hero };
    enum Skin { LEFT, RIGHT, FRONT};

public:
        virtual Type type() = 0;
        virtual ~Creature() {}
        Creature(size_t countSkin) : countSkin(countSkin) { m_skins.resize(countSkin); }

        QPixmap *getLeftSkin() { return (m_skins.size() >= 1) ? m_skins.at(LEFT) : nullptr; }
        QPixmap *getRightSkin() { return (m_skins.size() >= 2) ? m_skins.at(RIGHT) : nullptr; }
        QPixmap *getFrontSkin() { return (m_skins.size() >= 3) ? m_skins.at(FRONT) : nullptr; }

        void setLeftSkin(QPixmap *pixmap);
        void setRightSkin(QPixmap *pixmap);
        void setFrontSkin(QPixmap *pixmap);

private:
        QVector<QPixmap*> m_skins;
        const size_t countSkin;
};

#endif // CREATURE_H