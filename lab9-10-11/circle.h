#ifndef CIRCLE_H
#define CIRCLE_H

#include "abstractfigure.h"

class Circle : public AbstractFigure
{
public:
    Circle(QPointF& c, qreal& r): radius(r), center(c) {};
    virtual void draw(QPainter& painter, QPoint& pos) override;
    virtual bool isCursorOnFigure(QPoint pos) override;
    virtual void info() override;
    virtual void changeLocation(QPoint shift) override;
private:
    qreal radius;
    QPointF center{0,0};
};

#endif // CIRCLE_H
