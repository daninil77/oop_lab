#include "triangle.h"
#include <iostream>

void Triangle::draw(QPainter& painter, QPoint& pos)
{
    QPolygon triangle;
    triangle << _p1 << _p2 << _p3;
    painter.setBrush(QColor(0, 235, 0, 255));
    if (isCursorOnFigure(pos))
        painter.setBrush(QColor(0, 200, 0, 255));
    painter.drawPolygon(triangle);
}

bool Triangle::isCursorOnFigure(QPoint pos)
{
    QPolygon triangle;
    triangle << _p1 << _p2 << _p3;
    return triangle.containsPoint(pos, Qt::OddEvenFill);
}

void Triangle::info()
{
    std::cout << "\nFigure information: \n\tType: Triangle\n\tVertices: \n\t"
              << "(" << _p1.x() << "," << _p1.y() << ")\n\t"
              << "(" << _p2.x() << "," << _p2.y() << ")\n\t"
              << "(" << _p3.x() << "," << _p3.y() << ")" << std::endl;
}

void Triangle::changeLocation(QPoint shift)
{
    _p1 += shift;
    _p2 += shift;
    _p3 += shift;
}
