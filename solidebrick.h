#ifndef SOLIDEBRICK_H
#define SOLIDEBRICK_H

#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QPainter>

class SolideBrick : public QGraphicsItem
{
public:
        SolideBrick(QRectF boundingRect);
        ~SolideBrick();

public:
        QGraphicsLineItem *getColideLine() { return m_ColideLine; }
        QGraphicsLineItem *getUnColideLine() { return m_UnColideLine; }

protected:
           QRectF boundingRect() const;
           void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
           QGraphicsLineItem *m_ColideLine;
           QGraphicsLineItem *m_UnColideLine;
           QRectF m_boundRect;
};

#endif // SOLIDEBRICK_H
