#ifndef CSVWRITER_H
#define CSVWRITER_H
#include <QString>
#include <fstream>
#include <vector>
#include <lesson.h>

class CSVWriter
{
    std::ofstream fout;

    CSVWriter(const CSVWriter&) = delete;
    CSVWriter& operator=(const CSVWriter&) = delete;

public:
    CSVWriter(const QString& filename);
    ~CSVWriter();

    bool isopen() const;
    void writeles(Lesson l);

    //конструктор перемещения
    CSVWriter(CSVWriter&& orther);

    //оператор присваивания перемещением
    CSVWriter& operator= (CSVWriter&& orther);
};

#endif // CSVWRITER_H
