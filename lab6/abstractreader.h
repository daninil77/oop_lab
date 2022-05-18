#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H


#include <vector>
#include <lesson.h>
#include <fstream>

class AbstractReader
{
public:
    AbstractReader();
    virtual std::vector<Lesson> readAll() = 0;
    virtual bool is_open() const = 0;
    virtual operator bool () = 0;
    virtual AbstractReader& operator>> (Lesson &em) = 0;

};

#endif // ABSTRACTREADER_H
