#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <lesson.h>
#include <vector>
#include <abstractreader.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString fileName;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void read (AbstractReader& reader);

public slots:
    void FindLesson();
    void AddLesson();
private slots:
    void on_toolButton_clicked();
private:
    Ui::MainWindow *ui;

    std::vector<Lesson> lessons;


private:
    Ui::MainWindow *Ui;

    std::vector<Lesson> lesson;
};
#endif // MAINWINDOW_H
