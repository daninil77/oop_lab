#ifndef ORDINARY_H
#define ORDINARY_H
#include "lesson.h"

class Ordinary : public Lesson
{
public:
    int length;
    Ordinary();

    QString to_string();
};

#endif // ORDINARY_H
