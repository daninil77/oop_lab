#include "csvwriter.h"
#include <iostream>
#include <string>
#include <QString>
#include <vector>
#include <fstream>
#include <lesson.h>
#include<csvwriter.h>

CSVWriter::CSVWriter(const QString& filename)
{
    fout.open(filename.toStdString(), std::ios::app);
}

CSVWriter::~CSVWriter(){
    fout.close();
}

bool CSVWriter::isopen() const{return fout.is_open();};

//добавление строки в конец файла
void CSVWriter::writeles(Lesson l){
    if (fout.is_open())
    {
        fout << std::to_string(l.number) + ";" + l.nameLes.toStdString() + ";" + l.type.toStdString() + ";" + std::to_string(l.auditorium) << std::endl;
    }
    fout.close();
}

CSVWriter& CSVWriter::operator=(CSVWriter&& orher){
    fout = std::move(orher.fout);
    return *this;
}

CSVWriter::CSVWriter(CSVWriter&& orther){
    fout = std::move(orther.fout);
}
