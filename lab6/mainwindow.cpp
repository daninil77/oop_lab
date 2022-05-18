#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "mybrowser.h"
#include <csvreader.h>
#include <csvwriter.h>
#include <QString>
#include <QFileDialog>
#include <jsonreader.h>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FindLesson()
{
    ui->textBrowser->clear(); //Очищение браузера от продыдущих поисков.

    ui->textBrowser->GreenText("Searching...");
        //ui->textBrowser->append("Searching..");

    ui->textBrowser->append(ui->editSearch->text() + ":");
    for(const auto &l: lessons)
    {
        if(l.nameLes == ui->editSearch->text())
            ui->textBrowser->append(l.nameLes + ", " + l.type + ", " + QString::number(l.auditorium));
    }
}

void MainWindow::AddLesson(){

    //обрабатываем нажатие на кнопку buttonAdd
    Lesson l;
    l.number = ui->editID->text().toInt();;
    l.nameLes = ui->editLesson->text();
    l.type = ui->editType->text();
    l.auditorium = ui->editAuditorium->text().toInt();;

    //добавляем в вектор то, что считали
    lessons.push_back(l);

    //проверка на то, что файл открыт и если это так, записываем вектор в файл
    CSVWriter csvW(fileName);
    if(csvW.isopen())
    {
        //recording
        csvW.writeles(l);
        //clearing and redtext
        ui->textBrowser->clear();
        ui->textBrowser->RedText("Lesson is added.");
        ui->editID->clear();
        ui->editLesson->clear();
        ui->editType->clear();
        ui->editAuditorium->clear();
    }
    else
    {
        std::cout << "openning error" << std::endl;
    }
}

void MainWindow::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "/home",
                                                      tr("less (*.csv *.json)"));
    this-> fileName = fileName;
    //Открытие файла
    if(fileName.right(1) == QString::fromStdString("v")){
        CSVReader csv(fileName);
        if (csv.is_open()){

            //Чтение из файла в вектор
            lessons = csv.readAll();
        }
        else
        {
            std::cout << "openning error" << std::endl;
        }
    }
    if(fileName.right(1) == QString::fromStdString("n")){
        JSONReader json(fileName);
        if (json.is_open()){

            //Чтение из файла в вектор
            lessons = json.readAll();
        }

        else
        {
            std::cout << "openning error" << std::endl;
        }



    }

    // сортировка
        std::sort(lesson.begin(), lesson.end(), [](const Lesson &c1, const Lesson &c2){
            return c1.auditorium < c2.auditorium;
        });}
