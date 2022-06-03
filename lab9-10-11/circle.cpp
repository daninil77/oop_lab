#include "circle.h"
#include <iostream>

void Circle::draw(QPainter &painter, QPoint& pos)
{
    painter.setBrush(QColor(0, 0, 235, 255));
    if (isCursorOnFigure(pos))
        painter.setBrush(QColor(0, 0, 200, 255));
    painter.drawEllipse(center, radius, radius);
}

bool Circle::isCursorOnFigure(QPoint pos)
{
    QPointF subtract { pos - center };
    QPointF absSubtract { abs(subtract.x()), abs(subtract.y()) };
    return absSubtract.x() < radius && absSubtract.y() < radius;
}

void Circle::info()
{
    std::cout << "\nFigure information: \n\tType: Circle\n\tRadius: " << radius
              << "\n\tCenter: (" << center.x()
              << "," << center.y() << ")" << std::endl;
}

void Circle::changeLocation(QPoint shift)
{
    center += shift;
}
