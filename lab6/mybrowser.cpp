#include "mybrowser.h"
#include "mainwindow.h"
#include <QMainWindow>
#include "ui_mainwindow.h"

mybrowser::mybrowser(QWidget* parent)
    :QTextBrowser(parent)
{

}

void mybrowser::GreenText(QString text)

{
    auto color = this->textColor();
    this->setTextColor(Qt::green);
    this->append(text);
    this->setTextColor(color);
}


void mybrowser::RedText(QString text)

{
    auto color = this->textColor();
    this->setTextColor(Qt::red);
    this->append(text);
    this->setTextColor(color);
}
