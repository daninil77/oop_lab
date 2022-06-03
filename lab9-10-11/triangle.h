#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "abstractfigure.h"

class Triangle : public AbstractFigure
{
public:
    Triangle(QPoint& p1, QPoint& p2, QPoint& p3): _p1(p1), _p2(p2), _p3(p3) {};

    virtual void draw(QPainter& painter, QPoint& pos) override;
    virtual bool isCursorOnFigure(QPoint pos) override;
    virtual void info() override;
    virtual void changeLocation(QPoint shift) override;
private:
    QPoint _p1{0,0};
    QPoint _p2{0,0};
    QPoint _p3{0,0};
};

#endif // TRIANGLE_H
