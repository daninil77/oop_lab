#ifndef LESSON_H
#define LESSON_H
#include <QString>
#include <iostream>
class Lesson
{
public:
    int number;
    QString nameLes;
    QString type;
    int auditorium;
    Lesson();

    QString to_string();

    friend bool operator< (const Lesson& d1, const Lesson& d2){
        return d1.auditorium < d2.auditorium;
}
friend std::ostream& operator<< (std::ostream& fout, const Lesson& em){
    fout << "number: " << em.number << " nameLes: " << em.nameLes.toStdString() << ", auditorium: " << em.auditorium;
    return fout;
}
};

#endif // LESSON_H
