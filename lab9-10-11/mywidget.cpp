#include "mywidget.h"
#include "ui_mywidget.h"

#include "circle.h"
#include "square.h"
#include "triangle.h"


myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);
    setMouseTracking(true);

    Figures.clear();

    // параметры инициализации

    QPointF circleCenter = QPointF{250, 300};
    qreal circleRadius = 50;

    QPoint p1{500,350}, p2{550,250}, p3{600,350};

    QPointF squareLeftUpperAngle{350,250};
    qreal squareSide{100};

    //std::array<QPoint, 3> tri{QPoint{70, 70}, QPoint{150, 150}, QPoint{70, 50}};
    Figures.push_back(std::make_unique<Circle>(Circle{circleCenter, circleRadius}));
    Figures.push_back(std::make_unique<Triangle>(Triangle{p1,p2,p3}));
    Figures.push_back(std::make_unique<Square>(Square{squareLeftUpperAngle, squareSide}));
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    Figures.remove_if([](std::unique_ptr<AbstractFigure>& ptr)
    {
       return ptr->deleteStatus;
    });

    for (auto &f:Figures)
        f->draw(painter,mousePos);
}

void myWidget::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && (pressedFigure))
    {
        pressedFigure->changeLocation(event->pos() - mousePos);
    }

    mousePos = { event-> x() , event-> y() };
    update();
}

void myWidget::mousePressEvent(QMouseEvent *event)
{
    for (auto &f: Figures)
    {
 /*       if(f->isCursorOnFigure(event->pos()))
        {
                f->info();
        }*/

        if ((event->buttons() & Qt::LeftButton) && (f->isCursorOnFigure(event->pos())))
        {
            pressedFigure = f.get();
        }

        if ((event->buttons() & Qt::RightButton) && (f->isCursorOnFigure(event->pos())))
        {
            menuFigure = f.get();
            callMenu(mapToGlobal(event->pos()));
        }
    }
}

void myWidget::mouseReleaseEvent(QMouseEvent *event)
{
    pressedFigure = nullptr;
}

void myWidget::callMenu(QPoint pos)
{
    QMenu menu;
    connect(menu.addAction("Информация"),&QAction::triggered, this, &myWidget::showInfo);
    connect(menu.addAction("Удалить"),&QAction::triggered, this, &myWidget::setDelete);
    menu.exec(pos);
}

void myWidget::setDelete()
{
    menuFigure->deleteStatus = true;
}

void myWidget::showInfo()
{
    menuFigure->info();
}
