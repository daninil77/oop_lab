#ifndef SQUARE_H
#define SQUARE_H

#include "abstractfigure.h"

class Square : public AbstractFigure
{
public:
    Square(QPointF& point, qreal length): upleftAngle(point), side(length){};

    virtual void draw(QPainter& painter, QPoint& pos) override;
    virtual bool isCursorOnFigure(QPoint pos) override;
    virtual void info() override;
    virtual void changeLocation(QPoint shift) override;
private:
    QPointF upleftAngle{0,0};
    qreal side;
};

#endif // SQUARE_H
