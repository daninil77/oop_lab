#include "lesson.h"

QString Lesson::to_string() {
    return("Name: " + nameLes + "Auditorium: " + QString::number(auditorium));
}

Lesson::Lesson(){

}
