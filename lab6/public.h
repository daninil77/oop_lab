#ifndef PUBLIC_H
#define PUBLIC_H
#include "lesson.h"


class Public : public Lesson
{
public:
    int date;
    Public();

    QString to_string();
};

#endif // PUBLIC_H
