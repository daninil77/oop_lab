#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QMenu>
#include <abstractfigure.h>

QT_BEGIN_NAMESPACE
namespace Ui { class myWidget; }
QT_END_NAMESPACE

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();

private:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void callMenu(QPoint pos);

    QPoint mousePos = {0, 0};
    std::list<std::unique_ptr<AbstractFigure>> Figures;
    AbstractFigure* pressedFigure = nullptr;
    AbstractFigure* menuFigure = nullptr;
    Ui::myWidget *ui;

public slots:
    void setDelete();
    void showInfo();
};
#endif // MYWIDGET_H
