#include "square.h"
#include <iostream>

bool Square::isCursorOnFigure(QPoint pos)
{
    QRectF Square { upleftAngle.x(), upleftAngle.y(), side, side };
    return Square.contains(pos);
}

void Square::draw(QPainter& painter, QPoint& pos)
{
    painter.setBrush(QColor(235, 0, 0, 255));
    if (isCursorOnFigure(pos))
        painter.setBrush(QColor(200, 0, 0, 255));
    painter.drawRect(upleftAngle.x(), upleftAngle.y(), side, side);
}

void Square::info()
{
    std::cout << "\nFigure information: \n\tType: Square\n\tSide: " << side
              << "\n\tUpper left angle point: (" << upleftAngle.x()
              << "," << upleftAngle.y() << ")" << std::endl;
}

void Square::changeLocation(QPoint shift)
{
    upleftAngle += shift;
}

