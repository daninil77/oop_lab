#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

#include <QPainter>
#include <QMainWindow>

class AbstractFigure
{
public:
    virtual void draw(QPainter& painter, QPoint& pos) = 0;
    virtual bool isCursorOnFigure(QPoint pos) = 0;
    virtual void info() = 0;
    virtual void changeLocation(QPoint shift) = 0;
    bool deleteStatus = false;
};

#endif // ABSTRACTFIGURE_H
