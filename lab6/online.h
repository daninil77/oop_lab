#ifndef ONLINE_H
#define ONLINE_H
#include "lesson.h"

class Online : public Lesson
{
public:
    int password;
    Online();

    QString to_string();
};

#endif // ONLINE_H
