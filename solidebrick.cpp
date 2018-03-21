#include "solidebrick.h"

SolideBrick::SolideBrick(QRectF boundingRect) : m_boundRect(boundingRect)
{
    m_ColideLine = new QGraphicsLineItem(m_boundRect.x(), m_boundRect.y(),
                                        m_boundRect.x() + m_boundRect.width(), 1);
    m_UnColideLine = new QGraphicsLineItem(m_boundRect.x(), m_boundRect.y(),
                                          m_boundRect.x() + m_boundRect.width(), 1);
}

SolideBrick::~SolideBrick()
{
    delete m_ColideLine;
    delete m_UnColideLine;
}

QRectF SolideBrick::boundingRect() const
{
    return m_boundRect;
}

void SolideBrick::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(Qt::darkGreen, Qt::SolidPattern));
    painter->setPen(QPen(Qt::NoPen));
    painter->drawRect(m_boundRect);

    painter->setPen(QPen(Qt::SolidLine));
    m_ColideLine->setPos(this->x(), this->y() - 2);
    m_UnColideLine->setPos(this->x(), this->y() - 1);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
